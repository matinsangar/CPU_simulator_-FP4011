#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int public[32];
int binary_count[32];
int x, y, z, counter = 0;
char vaziat[8];
int i;
char command[1024];
char a[100], b[100]; // b vase jump dobareh tariif kardam
char cs[100];
char cd[100];
FILE *stream;
void parity_flag(int answer);
void zero_flag(int answer);
void sign_flag(int answer);
void ADD(int x, int y, int z);
void SUB(int x, int y, int z);
void MOV2(int x, int y);
void MOV1(int x, int y);
void ADDI(int x, int y, int z);
void SUBI(int x, int y, int z);
void SWP(int x, int y);
void AND(int x, int y, int z);
void OR(int x, int y, int z);
void XOR(int x, int y, int z);
void XORI(int x, int y, int z);
void ORI(int x, int y, int z);
void DUMP_REGS();
void DUMP_REG_F();
void INPUT();
void OUTPUT();
// Additional functions
void DIV(unsigned x, unsigned y);
void MULL(int x, int y);
void GUIDE();
void SQRT(int x);  // this function will move sqrt value in the S%d
void SQRTI(int x); // this function will Move sqqrt of %d into S%d  for exmp: S8 = 64;
// JUST FOR STACK
long stack[32];
int dish = -1;
void PUSH(int x);
void POP(int x);
// JUST FOR STACK
int main()
{
    char file_name[100];
    // printf("please give me your TXT file name : ");
    // scanf("%s", file_name);
    // printf("dorost kar mikoneh");
    int count = 0, count1 = 0;
    stream = fopen("database.txt", "r");
    // stream = fopen(file_name, "r");
    if (stream == NULL)
    {
        printf("Unable to open file. check please\n");
    }

    while (EOF != fscanf(stream, "%[^\n]\n", command))
    {

        counter++;
        if (command[0] == 'I' && command[4] == 'T') // input added space
        {
            command[5] = ' ';
        }
        else if (command[0] == 'O' && command[5] == 'T') // output added space
        {
            command[6] = ' ';
        }
        else if (command[0] == 'D' && command[8] == 'S') // dump_regs added space
        {
            command[9] = ' ';
        }
        else if (command[0] == 'D' && command[10] == 'F') // dump-regs_f added space
        {
            command[11] = ' ';
        }
        for (int i = 0; i < sizeof(command); i++)
        {
            if (command[i] == '/' && command[i + 1] == '/')
            {
                for (int z = i; z < sizeof(command); z++)
                {
                    command[z] = ' ';
                }
            }
        }

        for (i = 0; command[i] != ' '; i++)
        {
            a[i] = command[i];
        }
        // printf("%s\n", a); // to show commands line by line
        if (strcmp(a, "DIV") == 0)
        {
            sscanf(command, "DIV S%d, S%d", &x, &y);
            printf("salam");
            printf("%d", public[x] / public[y]);
            // DIV(x, y);
        }
        else if (strcmp(a, "div") == 0)
        {
            sscanf(command, "div S%d, S%d", &x, &y);

            DIV(x, y);
        }
        else if (strcmp(a, "GUIDE") == 0 || strcmp(a, "guide") == 0)
        {
            GUIDE();
        }

        else if (strcmp(a, "ADD") == 0)
        {
            sscanf(command, "ADD S%d, S%d, S%d", &x, &y, &z);
            ADD(x, y, z);
        }
        else if (strcmp(a, "add") == 0)
        {
            sscanf(command, "add S%d, S%d, S%d", &x, &y, &z);
            ADD(x, y, z);
        }
        else if (strcmp(a, "PUSH") == 0)
        {
            sscanf(command, "PUSH S%d", &x);
            PUSH(x);
        }
        else if (strcmp(a, "push") == 0)
        {
            sscanf(command, "push S%d", &x);
            PUSH(x);
        }
        else if (strcmp(a, "POP") == 0)
        {
            sscanf(command, "POP S%d", &x);
            POP(x);
        }
        else if (strcmp(a, "pop") == 0)
        {
            sscanf(command, "pop S%d", &x);
            POP(x);
        }
        else if (strcmp(a, "SQRT") == 0)
        {
            sscanf(command, "SQRT S%d", &x);
            SQRT(x);
        }
        else if (strcmp(a, "sqrt") == 0)
        {
            sscanf(command, "sqrt S%d", &x);
            SQRT(x);
        }
        else if (strcmp(a, "SQRTI") == 0)
        {
            sscanf(command, "SQRTI %d", &x);
            SQRTI(x);
        }
        else if (strcmp(a, "sqrti") == 0)
        {
            sscanf(command, "sqrti %d", &x);
            SQRTI(x);
        }
        else if (strcmp(a, "SUB") == 0)
        {
            sscanf(command, "SUB S%d, S%d, S%d", &x, &y, &z);
            SUB(x, y, z);
        }
        else if (strcmp(a, "sub") == 0)
        {
            sscanf(command, "sub S%d, S%d, S%d", &x, &y, &z);
            SUB(x, y, z);
        }
        else if (strcmp(a, "AND") == 0)
        {
            sscanf(command, "AND S%d, S%d, S%d", &x, &y, &z);
            AND(x, y, z);
        }
        else if (strcmp(a, "and") == 0)
        {
            sscanf(command, "and S%d, S%d, S%d", &x, &y, &z);
            AND(x, y, z);
        }
        else if (strcmp(a, "XOR") == 0)
        {
            sscanf(command, "XOR S%d, S%d, S%d", &x, &y, &z);
            XOR(x, y, z);
        }
        else if (strcmp(a, "xor") == 0)
        {
            sscanf(command, "xor S%d, S%d, S%d", &x, &y, &z);
            XOR(x, y, z);
        }
        else if (strcmp(a, "ORV") == 0)
        {
            sscanf(command, "OR S%d, S%d, S%d", &x, &y, &z);
            OR(x, y, z);
        }
        else if (strcmp(a, "orv") == 0)
        {
            sscanf(command, "or S%d, S%d, S%d", &x, &y, &z);
            OR(x, y, z);
        }
        else if (strcmp(a, "ADDI") == 0)
        {
            sscanf(command, "ADDI S%d, S%d, %d", &x, &y, &z);
            ADDI(x, y, z);
        }
        else if (strcmp(a, "addi") == 0)
        {
            sscanf(command, "addi S%d, S%d, %d", &x, &y, &z);
            ADDI(x, y, z);
        }
        else if (strcmp(a, "SUBI") == 0)
        {
            sscanf(command, "SUBI S%d, S%d, %d", &x, &y, &z);
            SUBI(x, y, z);
        }
        else if (strcmp(a, "subi") == 0)
        {
            sscanf(command, "subi S%d, S%d, %d", &x, &y, &z);
            SUBI(x, y, z);
        }
        else if (strcmp(a, "XORI") == 0)
        {
            sscanf(command, "XORI S%d, S%d, %d", &x, &y, &z);
            XORI(x, y, z);
        }
        else if (strcmp(a, "xori") == 0)
        {
            sscanf(command, "xori S%d, S%d, %d", &x, &y, &z);
            XORI(x, y, z);
        }
        else if (strcmp(a, "ORI") == 0)
        {
            sscanf(command, "ORI S%d, S%d, %d", &x, &y, &z);
            ORI(x, y, z);
        }
        else if (strcmp(a, "ori") == 0)
        {
            sscanf(command, "ori S%d, S%d, %d", &x, &y, &z);
            ORI(x, y, z);
        }
        else if (strcmp(a, "MOV") == 0)
        {
            int counts = 0;
            for (int j = 0; j < sizeof(command); j++)
            {
                if (command[j] == 'S')
                {
                    counts++;
                }
            }
            if (counts == 2)
            {
                sscanf(command, "MOV S%d, S%d", &x, &y);
                MOV2(x, y);
            }
            if (counts == 1)
            {
                sscanf(command, "MOV S%d, %d", &x, &y);
                MOV1(x, y);
            }
        }
        else if (strcmp(a, "SWP") == 0)
        {
            sscanf(command, "SWP S%d, S%d", &x, &y);
            SWP(x, y);
        }
        else if (strcmp(a, "swp") == 0)
        {
            sscanf(command, "swp S%d, S%d", &x, &y);
            SWP(x, y);
        }
        else if (strcmp(a, "DUMP_REG_F") == 0)
        {
            DUMP_REG_F();
        }
        else if (strcmp(a, "dump_reg_f") == 0)
        {
            DUMP_REG_F();
        }
        else if (strcmp(a, "DUMP_REGS") == 0)
        {
            DUMP_REGS();
        }
        else if (strcmp(a, "dump_regs") == 0)
        {
            DUMP_REGS();
        }
        else if (strcmp(a, "INPUT") == 0)
        {
            INPUT();
        }
        else if (strcmp(a, "input") == 0)
        {
            INPUT();
        }
        else if (strcmp(a, "OUTPUT") == 0)
        {
            OUTPUT();
        }
        else if (strcmp(a, "output") == 0)
        {
            OUTPUT();
        }
        else if (strcmp(a, "EXIT") == 0)
        {
            return 0;
        }
        else if (strcmp(a, "exit") == 0)
        {
            return 0;
        }
        else if (strcmp(a, "NICO") == 0)
        {
            sscanf(command, "NICO S%d, S%d", &x, &y);
            if (public[x] == public[y])
            {
                fclose(stream);
                int target = counter + 1;
                int place = 0;
                FILE *nico = fopen("database.txt", "r");
                while (EOF != fscanf(nico, "%[^\n]\n", command))
                {
                    place++;
                    if (place > target)
                    {
                        for (i = 0; command[i] != ' '; i++)
                        {
                            cd[i] = command[i];
                        }
                        // printf("%s", cd);
                        if (strcmp(cd, "DIV") == 0)
                        {
                            sscanf(command, "DIV S%d, S%d", &x, &y);
                            DIV(x, y);
                        }
                        else if (strcmp(cd, "div") == 0)
                        {
                            sscanf(command, "div S%d, S%d", &x, &y);
                            DIV(x, y);
                        }

                        else if (strcmp(cd, "ADD") == 0)
                        {

                            sscanf(command, "ADD S%d, S%d, S%d", &x, &y, &z);
                            ADD(x, y, z);
                        }
                        else if (strcmp(cd, "add") == 0)
                        {
                            sscanf(command, "add S%d, S%d, S%d", &x, &y, &z);
                            ADD(x, y, z);
                        }
                        else if (strcmp(cd, "PUSH") == 0)
                        {
                            sscanf(command, "PUSH S%d", &x);
                            PUSH(x);
                        }
                        else if (strcmp(cd, "push") == 0)
                        {
                            sscanf(command, "push S%d", &x);
                            PUSH(x);
                        }
                        else if (strcmp(cd, "GUIDE") == 0 || strcmp(a, "guide") == 0)
                        {
                            GUIDE();
                        }
                        else if (strcmp(cd, "POP") == 0)
                        {
                            sscanf(command, "POP S%d", &x);
                            POP(x);
                        }
                        else if (strcmp(cd, "pop") == 0)
                        {
                            sscanf(command, "pop S%d", &x);
                            POP(x);
                        }
                        else if (strcmp(a, "SQRT") == 0)
                        {
                            sscanf(command, "SQRT S%d", &x);
                            SQRT(x);
                        }
                        else if (strcmp(cd, "sqrt") == 0)
                        {
                            sscanf(command, "sqrt S%d", &x);
                            SQRT(x);
                        }
                        else if (strcmp(cd, "SQRTI") == 0)
                        {
                            sscanf(command, "SQRTI %d", &x);
                            SQRTI(x);
                        }
                        else if (strcmp(cd, "sqrti") == 0)
                        {
                            sscanf(command, "sqrti %d", &x);
                            SQRTI(x);
                        }

                        else if (strcmp(cd, "SUB") == 0)
                        {
                            sscanf(command, "SUB S%d, S%d, S%d", &x, &y, &z);
                            SUB(x, y, z);
                        }
                        else if (strcmp(cd, "sub") == 0)
                        {
                            sscanf(command, "sub S%d, S%d, S%d", &x, &y, &z);
                            SUB(x, y, z);
                        }

                        else if (strcmp(cd, "AND") == 0)
                        {
                            sscanf(command, "AND S%d, S%d, S%d", &x, &y, &z);
                            AND(x, y, z);
                        }
                        else if (strcmp(cd, "and") == 0)
                        {
                            sscanf(command, "and S%d, S%d, S%d", &x, &y, &z);
                            AND(x, y, z);
                        }
                        else if (strcmp(cd, "XOR") == 0)
                        {
                            sscanf(command, "XOR S%d, S%d, S%d", &x, &y, &z);
                            XOR(x, y, z);
                        }
                        else if (strcmp(cd, "xor") == 0)
                        {
                            sscanf(command, "xor S%d, S%d, S%d", &x, &y, &z);
                            XOR(x, y, z);
                        }
                        else if (strcmp(cd, "ORV") == 0)
                        {
                            sscanf(command, "OR S%d, S%d, S%d", &x, &y, &z);
                            OR(x, y, z);
                        }
                        else if (strcmp(cd, "orv") == 0)
                        {
                            sscanf(command, "or S%d, S%d, S%d", &x, &y, &z);
                            OR(x, y, z);
                        }
                        else if (strcmp(cd, "ADDI") == 0)
                        {
                            sscanf(command, "ADDI S%d, S%d, %d", &x, &y, &z);
                            ADDI(x, y, z);
                        }
                        else if (strcmp(cd, "addi") == 0)
                        {
                            sscanf(command, "addi S%d, S%d, %d", &x, &y, &z);
                            ADDI(x, y, z);
                        }
                        else if (strcmp(cd, "SUBI") == 0)
                        {
                            sscanf(command, "SUBI S%d, S%d, %d", &x, &y, &z);
                            SUBI(x, y, z);
                        }
                        else if (strcmp(cd, "subi") == 0)
                        {
                            sscanf(command, "subi S%d, S%d, %d", &x, &y, &z);
                            SUBI(x, y, z);
                        }
                        else if (strcmp(cd, "XORI") == 0)
                        {
                            sscanf(command, "XORI S%d, S%d, %d", &x, &y, &z);
                            XORI(x, y, z);
                        }
                        else if (strcmp(cd, "xori") == 0)
                        {
                            sscanf(command, "xori S%d, S%d, %d", &x, &y, &z);
                            XORI(x, y, z);
                        }
                        else if (strcmp(cd, "ORI") == 0)
                        {
                            sscanf(command, "ORI S%d, S%d, %d", &x, &y, &z);
                            ORI(x, y, z);
                        }
                        else if (strcmp(cd, "ori") == 0)
                        {
                            sscanf(command, "ori S%d, S%d, %d", &x, &y, &z);
                            ORI(x, y, z);
                        }
                        else if (strcmp(cd, "MOV") == 0)
                        {
                            int counts = 0;
                            for (int j = 0; j < sizeof(command); j++)
                            {
                                if (command[j] == 'S')
                                {
                                    counts++;
                                }
                            }
                            if (counts == 2)
                            {
                                sscanf(command, "MOV S%d, S%d", &x, &y);
                                MOV2(x, y);
                            }
                            if (counts == 1)
                            {
                                sscanf(command, "MOV S%d, %d", &x, &y);
                                MOV1(x, y);
                            }
                        }
                        else if (strcmp(cd, "SWP") == 0)
                        {
                            sscanf(command, "SWP S%d, S%d", &x, &y);
                            SWP(x, y);
                        }
                        else if (strcmp(cd, "swp") == 0)
                        {
                            sscanf(command, "swp S%d, S%d", &x, &y);
                            SWP(x, y);
                        }
                        else if (strcmp(cd, "DUMP_REG_F") == 0)
                        {
                            DUMP_REG_F();
                        }
                        else if (strcmp(cd, "dump_reg_f") == 0)
                        {
                            DUMP_REG_F();
                        }
                        else if (strcmp(cd, "DUMP_REGS") == 0)
                        {
                            DUMP_REGS();
                        }
                        else if (strcmp(cd, "dump_regs") == 0)
                        {
                            DUMP_REGS();
                        }
                        else if (strcmp(cd, "INPUT") == 0)
                        {
                            INPUT();
                        }
                        else if (strcmp(cd, "input") == 0)
                        {
                            INPUT();
                        }
                        else if (strcmp(cd, "OUTPUT") == 0)
                        {
                            OUTPUT();
                        }
                        else if (strcmp(cd, "output") == 0)
                        {
                            OUTPUT();
                        }
                        else if (strcmp(cd, "EXIT") == 0)
                        {
                            return 0;
                        }
                        else if (strcmp(cd, "exit") == 0)
                        {
                            return 0;
                        }
                        else
                        {
                            printf("Unknown Command");
                        }
                    }
                }
                fclose(nico);
            }
        }
        else if (strcmp(a, "JMP") == 0)
        {
            sscanf(command, "JMP %d", &x);
            fclose(stream);
            int target = x;
            int place = 0;
            FILE *jump = fopen("database.txt", "r");
            while (EOF != fscanf(jump, "%[^\n]\n", command))
            {
                place++;
                if (place > target)
                {

                    for (i = 0; command[i] != ' '; i++)
                    {
                        cs[i] = command[i];
                    }
                    //  printf("%s", cs);
                    if (command[0] == 'I' && command[4] == 'T') // input added space
                    {
                        command[5] = ' ';
                    }
                    else if (command[0] == 'O' && command[5] == 'T') // output added space
                    {
                        command[6] = ' ';
                    }
                    else if (command[0] == 'D' && command[8] == 'S') // dump_regs added space
                    {
                        command[9] = ' ';
                    }
                    else if (command[0] == 'D' && command[10] == 'F') // dump-regs_f added space
                    {
                        command[11] = ' ';
                    }
                    for (int i = 0; i < sizeof(command); i++)
                    {
                        if (command[i] == '/' && command[i + 1] == '/')
                        {
                            for (int z = i; z < sizeof(command); z++)
                            {
                                command[z] = ' ';
                            }
                        }
                    }
                    if (strcmp(cs, "ADD") == 0)
                    {
                        ;
                        sscanf(command, "ADD S%d, S%d, S%d", &x, &y, &z);
                        ADD(x, y, z);
                    }
                    else if (strcmp(cs, "SUB") == 0)
                    {
                        sscanf(command, "SUB S%d, S%d, S%d", &x, &y, &z);
                        SUB(x, y, z);
                    }

                    else if (strcmp(cs, "AND") == 0)
                    {
                        sscanf(command, "AND S%d, S%d, S%d", &x, &y, &z);
                        AND(x, y, z);
                    }
                    else if (strcmp(cs, "XOR") == 0)
                    {
                        sscanf(command, "XOR S%d ,S%d ,S%d", &x, &y, &z);
                        XOR(x, y, z);
                    }
                    else if (strcmp(cs, "OR") == 0)
                    {
                        sscanf(command, "OR S%d, S%d, S%d", &x, &y, &z);
                        OR(x, y, z);
                    }
                    else if (strcmp(cs, "ADDI") == 0)
                    {
                        sscanf(command, "ADDI S%d, S%d, S%d", &x, &y, &z);
                        ADDI(x, y, z);
                    }

                    else if (strcmp(cs, "SUBI") == 0)
                    {
                        sscanf(command, "SUBI S%d, S%d, S%d", &x, &y, &z);
                        SUBI(x, y, z);
                    }
                    else if (strcmp(cs, "XORI") == 0)
                    {
                        sscanf(command, "XORI S%d, S%d, S%d", &x, &y, &z);
                        XORI(x, y, z);
                    }
                    else if (strcmp(cs, "ORI") == 0)
                    {
                        sscanf(command, "ORI S%d, S%d, S%d", &x, &y, &z);
                        ORI(x, y, z);
                    }
                    else if (strcmp(cs, "MOV") == 0)
                    {
                        int counts = 0;
                        for (int j = 0; j < sizeof(command); j++)
                        {
                            if (command[j] == 'S')
                            {
                                counts++; // if we have 2  s const or 1 !
                            }
                        }
                        if (counts == 2)
                        {
                            sscanf(command, "MOV S%d, S%d", &x, &y);
                            MOV2(x, y);
                        }
                        if (counts == 1)
                        {
                            sscanf(command, "MOV S%d, %d", &x, &y);
                            MOV1(x, y);
                            printf("1\n");
                        }
                    }
                    else if (strcmp(cs, "SWP") == 0)
                    {
                        sscanf(command, "SWP S%d, S%d", &x, &y);
                        SWP(x, y);
                    }
                    else if (strcmp(cs, "DUMP_REGS") == 0)
                    {
                        printf("kfdka");
                        DUMP_REGS();
                    }
                    else if (strcmp(cs, "DUMP_REG_F") == 0)
                    {
                        DUMP_REG_F();
                    }
                    else if (strcmp(cs, "INPUT") == 0)
                    {
                        INPUT();
                    }
                    else if (strcmp(cs, "OUTPUT") == 0)
                    {

                        OUTPUT();
                    }
                    else if (strcmp(cs, "EXIT") == 0)
                    {
                        fclose(jump);
                        return 0;
                    }
                }
            }
            fclose(jump);
            return 0;
        }

        else
        {
            printf("Unknown Command");
        }
    }
    fclose(stream);
    return 0;
}
void parity_flag(int answer)
{
    if (answer == 0)
    {
        vaziat[0] = 0;
    }
    i = 0;
    int count1 = 0;
    for (; answer > 0;)
    {
        binary_count[i++] = answer % 2;
        answer /= 2;
    }
    for (int j = i - 1; j >= 0; j--)
    {
        if (binary_count[j] == 1)
        {
            count1++;
        }
    }
    if (count1 % 2 == 0)
    {
        vaziat[0] = 0;
    }
    else
    {
        vaziat[0] = 1;
    }
}
void zero_flag(int answer)
{
    if (answer == 0)
    {
        vaziat[1] = 1;
    }
    else
    {
        vaziat[1] = 0;
    }
}
void sign_flag(int answer)
{
    if (answer < 0)
    {
        vaziat[2] = 1;
    }
    else
    {
        vaziat[2] = 0;
    }
}
void ADD(x, y, z)
{
    public[x] = public[y] + public[z];
    if (public[y] > 0 && public[z] > 0 && public[x] < 0) // owerflow checking
    {
        vaziat[5] = 1;
        public[x] = 0;
    }
    else if (public[y] < 0 && public[z] < 0 && public[x] > 0)
    {
        vaziat[5] = 1;
        public[x] = 0;
    }
    else
    {
        vaziat[5] = 0;
    }
    zero_flag(public[x]);
    sign_flag(public[x]);
    parity_flag(public[x]);

    // printf("%ld",public[x]);
}
void SUB(x, y, z)
{
    public[x] = public[y] - public[z];
    if (public[y] < 0 && public[z] > 0 && public[x] > 0) // owerflow checking
    {
        vaziat[5] = 1;
        public[x] = 0;
    }
    else if (public[y] > 0 && public[z] < 0 && public[x] < 0)
    {
        vaziat[5] = 1;
        public[x] = 0;
    }
    else
    {
        vaziat[5] = 0;
    }
    zero_flag(public[x]);
    sign_flag(public[x]);
    parity_flag(public[x]);
}
void MOV2(x, y)
{
    public[x] = public[y];
    // printf("%ld %ld",public[x],public[y]);
}
void MOV1(x, y)
{
    public[x] = y;
    // printf("%d",public[x]);
}
void ADDI(x, y, z)
{
    public[x] = public[y] + z;
    if (public[y] > 0 && z > 0 && public[x] < 0) // owerflow checking
    {
        vaziat[5] = 1;
        public[x] = 0;
    }
    else if (public[y] < 0 && z < 0 && public[x] > 0)
    {
        vaziat[5] = 1;
        public[x] = 0;
    }
    else
    {
        vaziat[5] = 0;
    }
    zero_flag(public[x]);
    sign_flag(public[x]);
    parity_flag(public[x]);
}
void SUBI(x, y, z)
{
    public[x] = public[y] - z;
    if (public[y] < 0 && z > 0 && public[x] > 0) // owerflow checking
    {
        vaziat[5] = 1;
        public[x] = 0;
    }
    else if (public[y] > 0 && z < 0 && public[x] < 0)
    {
        vaziat[5] = 1;
        public[x] = 0;
    }
    else
    {
        vaziat[5] = 0;
    }
    zero_flag(public[x]);
    sign_flag(public[x]);
    parity_flag(public[x]);
}
void SWP(x, y)
{
    int temp;
    temp = public[x];
    public[x] = public[y];
    public[y] = temp;
}
void DUMP_REGS()
{
    for (int i = 0; i < 32; i++)
    {
        // printf("%ld", public[i]);
        printf("{%d : %d} ", i, public[i]);
    }
    for (int i = 0; i < 8; i++)
    {
        printf("%d", vaziat[i]);
    }
}
void DUMP_REG_F()
{
    FILE *dump_FILE = fopen("regs.txt", "w");
    for (int i = 0; i < 32; i++)
    {
        putw(public[i], dump_FILE);
    }
    for (int i = 0; i < 8; i++)
    {
        putw(vaziat[i], dump_FILE);
    }
}
void INPUT()
{
    printf("please give me your S0 : ");
    scanf("%d", &public[0]);
    // printf("%ld", public[0]);
}
void OUTPUT()
{
    printf("%d", public[0]);
}
void PUSH(int x)
{
    dish += 1; // static stack
    stack[dish] = public[x];
    public[x] = 0; // to reset publix[x]
}
void POP(int x)
{
    if (dish == -1)
    {
        printf("Underflow State: Stack already empty, can't remove any element\n");
    }
    else
    {
        command[x] = stack[dish];
        stack[dish] = 0;
        dish -= 1;
    }
}
void AND(x, y, z)
{
    public[x] = public[y] & public[z];
    zero_flag(public[x]);
    sign_flag(public[x]);
    parity_flag(public[x]);
}
void OR(x, y, z)
{
    public[x] = public[y] | public[z];
    zero_flag(public[x]);
    sign_flag(public[x]);
    parity_flag(public[x]);
}
void XOR(int x, int y, int z)
{
    public[x] = public[y] ^ public[z];
    zero_flag(public[x]);
    sign_flag(public[x]);
    parity_flag(public[x]);
}
void XORI(x, y, z)
{
    public[x] = public[y] ^ z;
    zero_flag(public[x]);
    sign_flag(public[x]);
    parity_flag(public[x]);
}
void ORI(x, y, z)
{
    public[x] = public[y] | z;
    zero_flag(public[x]);
    sign_flag(public[x]);
    parity_flag(public[x]);
}
void DIV(unsigned x, unsigned y)
{

    public[x] = public[x] / public[y];
    public[y] = public[x] % public[y];
    zero_flag(public[x]);
    sign_flag(public[x]);
    parity_flag(public[x]);
}
void MULL(int x, int y)
{
    int mull = public[x] * public[y];
    public[x] = mull + 4;
    public[y] = mull - 4;
    // CHECKING OVERFLOW
    if (public[x] > 0 && public[y] > 0 && mull < 0)
    {
        vaziat[5] = 1;
    }
    else if (public[x] < 0 && public[y] < 0 && mull < 0)
    {
        vaziat[5] = 1;
    }
    else if (public[x] > 0 && public[y] < 0 && mull > 0)
    {
        vaziat[5] = 1;
    }
    else if (public[x] < 0 && public[y] > 0 && mull > 0)
    {
        vaziat[5] = 1;
    }
    else
    {
        vaziat[5] = 0;
    }

    zero_flag(public[x]);
    sign_flag(public[x]);
    parity_flag(public[x]);
}
void GUIDE()
{
    printf("*ADD function will  dropped to constant into another constant name SRT for example at s 0 S1 and S2 will drop S1 and S2 into s0");
    printf("*ADDI*  command will add one constant and one number and drop it into SRT for example ADDI  s0 S2 and 3 will add S2 to S3 and then drop it into S zero on the other hand  *SUBBI*  will subtract  SRS from one integer and then drop it into SRT");
    printf("*ANDI*   the same with AND but it would and one SRS with one integer and then drop it into SRT *XORI * will  or  SRS with one integer  and then drop it into SRT for example XORI   S0  S1 and 5  will xor five with S1 and then drop it into SRT");
    printf(" *ORI* command  will or SRS with one integer and then drop it into ORI  for example ORI S0, S1 , 4 will or S1 and 4 and then drop it into a  S0 *SWP*  will swap  value of the SRT and SRS for example if we have 10  in SRT and 20  in SRS and swap them  we would have 20  an SRT and 10 in  SRS");
    printf(" *input* command  will receive s0 value from user *output* command  will show s0 value  in console");
    printf(" *JMP*  jump command  will jump in your lines of command  the most important rule in this command is that you can't jump to  your previous command  because of infinite Loop");
    printf(" in the end *exit* command will finish your process\nthanks for reading this");
    printf("\n\n\nmade by MATIN AMIN SABOURI");
}
void SQRT(int x)
{
    public[x] = public[x] * public[x];
}
void SQRTI(int x)
{
    if (x < 31 && x > 0)
    {
        public[x] = x * x;
    }
    else
    {
        printf("ERROR : SQRTI function only works in range(1,31)\n");
    }
}
