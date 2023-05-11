import streamlit as st
import subprocess
import os
#import streamlit_session_state as session_state
if 'c_code' not in st.session_state:
    st.session_state['c_code'] = ''
if 'debug' not in st.session_state:
    st.session_state['debug'] = ''


st.title('Pascal to C Compiler')

pascal_code = st.text_area(label="Enter your Pascal code here: :sunglasses:",value='''program gcd(input, output);
var
  x, y: integer;
function gcd(a, b: integer): integer;
begin
  if b = 0 then gcd := a
  else gcd := gcd(b, a mod b);
end;
begin
  read(x, y);
  write(gcd(x, y));
end.''', height=10)


# 将代码分割为多行
lines = pascal_code.split('\n')

# 为每一行添加行号
lines_with_line_numbers = [f"{i+1:02d}: {line}" for i, line in enumerate(lines)]
# print(lines_with_line_numbers)

# 将代码重新组合为一个字符串
pas_linenums = '\n'.join(lines_with_line_numbers)


st.markdown("```pascal\n"+pas_linenums+"\n```")


user_input = st.text_input("Enter your input for the program here:")

        
        
if st.button("Run Pascal code"):
    with open('temp.pas', 'w') as f:
        f.write(pascal_code)
    command = 'fpc temp.pas'
    command2 = 'temp.exe'
    process = subprocess.Popen(command, stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=True)
    process2 = subprocess.Popen(command2, stdin=subprocess.PIPE,stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=True, text=True)
    stdout, stderr = process2.communicate(user_input)
    print(stdout+'.')
    print(stderr+'.')
    if stderr:
        st.write(f'##### Error for pas: {stderr}')
    else:
        st.write(f'##### Output for pas: {stdout}')

if st.button("Compile Pascal to C"):
    with open('temp.pas', 'w') as f:
        f.write(pascal_code)
    command = 'parser -f temp.pas -o output.c -d debug.txt'
    process = subprocess.Popen(command, stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=True)
    stdout, stderr = process.communicate()
    if stderr:
        st.write(f'Error: {stderr.decode()}')
    else:
        with open('output.c', 'r') as f:
            st.session_state.c_code = f.read()
        with open('debug.txt', 'r') as f:
            st.session_state.debug = f.read()
        # st.session_state.debug.replace("ERROR","<font color=\'red\'>ERROR</font>")
        str = st.session_state.debug.replace('(','***(').replace(')',')***').replace("ERROR","<font color='red'>ERROR</font>").replace('.','.\n')
        print(str)
        st.write(str, unsafe_allow_html=True)
        
        lines = st.session_state.c_code.split('\n')

        # 为每一行添加行号
        lines_with_line_numbers = [f"{i+1:02d}: {line}" for i, line in enumerate(lines)]

        # 将代码重新组合为一个字符串
        c_linenums = '\n'.join(lines_with_line_numbers)

        st.markdown("```c \n"+c_linenums+"\n```")

if st.button("Run C code"):
    command1 = '''gcc output.c -o demo'''
    command2 = '''demo'''
    process1 = subprocess.Popen(command1, stdout=subprocess.PIPE, stdin=subprocess.PIPE, stderr=subprocess.PIPE, shell=True, text=True)
    stdout1, stderr1 = process1.communicate()
    process2 = subprocess.Popen(command2, stdout=subprocess.PIPE, stdin=subprocess.PIPE, stderr=subprocess.PIPE, shell=True, text=True)
    stdout2, stderr2 = process2.communicate(user_input)
    # user_input
    lines = st.session_state.c_code.split('\n')

        # 为每一行添加行号
    lines_with_line_numbers = [f"{i+1:02d}: {line}" for i, line in enumerate(lines)]

        # 将代码重新组合为一个字符串
    c_linenums = '\n'.join(lines_with_line_numbers)
    st.markdown("```c \n"+c_linenums+"\n```")

    if stderr2:
        st.write(f'##### Error for C:\n {stderr2}')
    else:
        st.write(f'##### Output for C:\n {stdout2}')
    








