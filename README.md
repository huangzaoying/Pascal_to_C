# Pascal_to_C
using yacc and lex Compiler Pascal to C

# Environment Config
1. Windows 10
2. flex version 2.5.4
3. bison (GNU Bison) 2.4.1
4. gcc version 8.1.0
5. Free Pascal Compiler 3.2.2
# Compliler:
make

# Terminal operation:
del test.c test.txt
(-f sourcefile -o outfile -d debugfile)
parser -f test.pas -o test.c -d test.txt 

# Front-end start-up
#pip install streamlit
streamlit run demo.py