// 210426 Написал на основе проекта https://github.com/vurdalakov/crc32
// (Copyright (c) 2012 Vurdalakov http://www.vurdalakov.net)
// утилиту, которая вычисляет от двоичного файла CRC32 так же, как
// это делает блок аппаратного вычисления CRC32 микроконтроллера STM32,
// и добавляет её в конец файла.
// Подробности см. в статье [].
// Если запустить crc32 без опций, то выведется подсказка.
// Если в командной строке будет указано только одно имя файла,
// то будет выведена в HEX-форме контрольная сумма CRC32 этого файла.
// Если в командной строке указано 2 имени файла, то будет подсчитана
// CRC32 первого файла, создан заново второй файл, и в его конец
// будет добавлена вычисленная контрольная сумма первого файла.
// Если оба имени совпадают, то входной файл будет перезаписан.
//
// The MIT License (MIT)
//
// Permission is hereby granted, free of charge, to any person
// obtaining a copy of this software and associated documentation
// files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use,
// copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following
// conditions:
//
// The above copyright notice and this permission notice shall be
// included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
// OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
// HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
// WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
// OTHER DEALINGS IN THE SOFTWARE.

namespace STM32.Crc32
{
   using System;
   using System.IO;
   using System.Security.Cryptography;

   class Program
   {
      static byte[] src = new byte[4];
      static byte[] dst = new byte[4];
      const UInt32 POLY = 0x04C11DB7;
      static UInt32 crc = 0xFFFFFFFF;

      // Возвратит 0, если не прочитано ни одного байта из потока stream.
      static int reorder4(ref Stream stream)
      {
         int rbyte;
         int readed = 0;

         for (int i = 0; i < 4; i++)
         {
            rbyte = stream.ReadByte();
            if (-1 == rbyte)
            {
               src[i] = 0xFF;
            }
            else
            {
               src[i] = (byte)rbyte;
               readed++;
            }
            dst[3 - i] = src[i];
         }

         return readed;
      }

      static UInt32 crc32_formula_normal_STM32(ref Stream stream)
      {
         int readed;

         while (true)
         {
            readed = reorder4(ref stream);
            if (0 == readed)
               break;
            for (int i = 0; i < 4; i++)
            {
               crc = crc ^ ((UInt32)dst[i] << 24);
               for (int bit = 0; bit < 8; bit++)
               {
                  if (0 != (crc & (1 << 31)))
                     crc = (crc << 1) ^ POLY;
                  else
                     crc = (crc << 1);
               }
            }
         }
         return crc;
      }

      static void Main(string[] args)
      {
         CommandLineParser commandLineParser = new CommandLineParser();

         if (String.IsNullOrEmpty(commandLineParser.srcFN))
         {
            AssemblyInfo assemblyInfo = AssemblyInfo.Create();

            Console.WriteLine("{0} v{1} - {2}\nAppend CRC32 to srcfile\n\nUsage:\n\tcrc32 [[srcfile] dstfile]",
                assemblyInfo.ProductName, assemblyInfo.FileVersion, assemblyInfo.Description);

            return;
         }

         UInt32 hash;
         Stream srcSTREAM = new FileStream(commandLineParser.srcFN, FileMode.Open, FileAccess.Read, FileShare.Read);
         hash = crc32_formula_normal_STM32(ref srcSTREAM);

         if (null == commandLineParser.dstFN)
         {
            // В командной строке второе имя файла не указано,
            // поэтому будет только выведена вычисленная
            // контрольная сумма от файла с первым именем.
            Console.WriteLine("{0:X}", hash);
         }
         else
         {
            // В командной строке указано 2 имени.
            // Перемотаем входной файл в начало:
            srcSTREAM.Seek(0, SeekOrigin.Begin);
            // Создадим новый массив, размер которого равен
            // размеру входного файла в байтах плюс дополнение до
            // размера, нацело кратного 4:
            long appendCNT = (0 == (srcSTREAM.Length % 4)) ? 0 : 4 - (srcSTREAM.Length % 4);
            int datasize = (int)(srcSTREAM.Length + appendCNT);
            byte[] dataarr = new byte[datasize];
            // Цикл, в котором содержимое исходного файла
            // копируется в массив:
            long idx = 0;
            while (true)
            {
               int rbyte = srcSTREAM.ReadByte();
               if (-1 == rbyte)
                  break;
               dataarr[idx++] = (byte)rbyte;
            }
            srcSTREAM.Close();
            // Дополнение данными массива, если это необходимо:
            while (0 != appendCNT)
            {
               dataarr[idx++] = 0xFF;
               appendCNT--;
            }
            // Удалим выходной файл, если он существует.
            File.Delete(commandLineParser.dstFN);
            // Создадим поток для выходного файла.
            Stream dstSTREAM = new FileStream(commandLineParser.dstFN,
                                              FileMode.CreateNew,
                                              FileAccess.Write,
                                              FileShare.None);
            dstSTREAM.Write(dataarr, 0, datasize);
            // Добавление в конец выходного файла вычисленной
            // контрольной суммы:
            dst = BitConverter.GetBytes(hash);
            dstSTREAM.Write(dst, 0, 4);
         }
      }
   }
}
