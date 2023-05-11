import subprocess
import os
import time

source_dir = "D:\\Desktop\\Pascal_to_C\\test\\test_error"
os.chdir(source_dir)

output_folder = "output"
if not os.path.exists(output_folder):
    os.makedirs(output_folder)

for file in os.listdir():
    print(file)
    if file.endswith('.pas'):
        input = os.path.join(source_dir, file)
        output = os.path.join(source_dir, output_folder, file[:-3]+'c')
        out = os.path.join(source_dir, output_folder, file[:-3]+'txt')
        command = 'parser -f {} -o {} -d {}'.format(input,output,out)
        print(command)
        subprocess.run(command, shell=True, cwd="D:\\Desktop\\SimplePascal2C\\src")
        time.sleep(1)
        # Now open the output .txt file and check if it contains <ERROR>
        print(out)
        with open(out, 'r') as f:
            content = f.read()
            if 'ERROR' in content:
                print("Test case failed: Error found in ", file)
            else:
                print("Test case passed: No error found in ", file)
