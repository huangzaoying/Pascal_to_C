import subprocess
import os
import time

def recursive_test_files(current_dir, source_dir):
    for file in os.listdir(current_dir):
        file_path = os.path.join(current_dir, file)
        if os.path.isdir(file_path):
            recursive_test_files(file_path, source_dir)
        elif file.endswith('.pas'):
            c_code_folder = os.path.join(current_dir, "c_code")
            c_output_folder = os.path.join(current_dir, "c_output")
            if not os.path.exists(c_code_folder):
                os.makedirs(c_code_folder)
            if not os.path.exists(c_output_folder):
                os.makedirs(c_output_folder)

            input = os.path.join(current_dir, file)
            output = os.path.join(c_code_folder, file[:-3]+'c')
            out = os.path.join(c_code_folder, file[:-3]+'txt')
            outfile = os.path.join(c_output_folder, file[:-3]+'txt')
            
            # 删除已有的代码和错误报告文件
            if os.path.exists(output):
                os.remove(output)
            if os.path.exists(out):
                os.remove(out)
            if os.path.exists(outfile):
                os.remove(outfile)
                
            command = 'parser -f {} -o {} -d {}'.format(input, output, out)
            # print(command)
            subprocess.run(command, shell=True, cwd="D:\\Desktop\\Pascal_to_C\\src")
            time.sleep(0.1)
            # Now open the output .txt file and check if it contains <ERROR>
            # print(out)
            error_found = False
            with open(out, 'r') as f:
                content = f.read()
                if 'ERROR' in content:
                    print("[  ok  ]Test case failed: Error found in ", input)
                    error_found = True
                else:
                    print("[  ok  ]Test case passed: No error found in ", input)

            # 如果没有错误，编译 Pascal 代码和对应的 C 代码
            if not error_found:
                command = 'gcc -o {} {}'.format(output[:-2]+'exe', output)
                print(command)
                subprocess.run(command, shell=True)
                time.sleep(0.1)
                # 运行编译后的可执行文件，并将输出重定向到 output.txt
                with open(outfile, 'w') as output_file:
                    command = output[:-2]+'exe'
                    print("[   run] ", command)
                    subprocess.run(command, shell=True, stdout=output_file, stderr=subprocess.STDOUT)
                    time.sleep(1)

source_dir = r"D:\\Desktop\\Pascal_to_C\\src\\test"
os.chdir(source_dir)

recursive_test_files(source_dir, source_dir)