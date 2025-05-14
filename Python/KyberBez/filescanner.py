import os
import argparse

def scan_files(directory, extensions, output_file):
    extensions = [ext.lower() for ext in extensions]
    
    with open(output_file, 'w') as outfile:
        for root, dirs, files in os.walk(directory):
            for file in files:
                _, ext = os.path.splitext(file)
                ext = ext.lower()
                
                if ext in extensions:
                    outfile.write(os.path.join(root, file) + '\n')

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='File-scanner')
    parser.add_argument('-d', '--directory', dest='directory', required=True, type=str, help='Путь к директории для сканирования')
    parser.add_argument('-e', '--ext', dest='extensions', required=True, type=str, help='Расширения файлов через запятую (пример: txt,php)')
    parser.add_argument('-o', '--output', dest='output_file', required=False, type=str, help='Путь к выходному файлу')

    args = parser.parse_args()

    extensions_list = ['.'+ext.strip() for ext in args.extensions.split(',')]
    out = 'files.txt' if not args.output_file else args.output_file

    scan_files(args.directory, extensions_list, out)
    print(f"Сканирование завершено. Результаты записаны в {out}.")