#include <stdio.h>
#include <stdint.h>
#include <string.h>

//A brainF interpreter with amogus slang
//Might turn into compiler. Who knows
//Man i really should use this time in something more useful

//I call it, BFA (BrainFrickingAmogus)

uint8_t bfa_src_code[] = "amogus imposter voted amogus crewmate amogus imposter amogus crewmate ";
uint8_t bfa_output_code[4 * 1024]; //4KBs




void bfa_compile(){
    //Inspired by the "I-USE-ARCH-BTW" lang, each of these "instructions" are seperated with a space

    //Compile into a bytecode version for simpler executing.
    //codes:
    //0x0: inc data
    //0x1: dec data
    //0x2: inc dataptr
    //0x3: dec dataptr
    //0x4: output data
    //0x5: read data
    //0x6: [ (open bracket loop condition)
    //0x7: ] (Close bracket loop condition)

    //Amogus slang equivelant (in order)

    //0x0: amogus
    //0x1: sugoma
    //0x2: sussy
    //0x3: sus
    //0x4: voted
    //0x5: vented
    //0x6: imposter
    //0x7: crewmate

    //Anything else will be ignored.

    //Longest one is 8 chars so, That's how long the string decoding takes before deciding it's not valid.

    uint8_t tmp[9];
    uint8_t tmp_ptr = 0;

    uint32_t output_ptr = 0;

    for(uint32_t i = 0; i < sizeof(bfa_src_code); i++){
        //Conversion if tmp_ptr == 0
        if(tmp_ptr == 0){
            char* instruction_slang[] = {
                "amogus",
                "sugoma",
                "sussy",
                "sus",
                "voted",
                "vented",
                "imposter",
                "crewmate",
            };

            for(uint32_t i2 = 0; i2 < 8; i2++){
                if(strcmp(tmp, instruction_slang[i2]) == 0){
                    bfa_output_code[output_ptr] = i2;
                    output_ptr++;
                }
            }
        }

        if(bfa_src_code[i] == ' ' || tmp_ptr == 9){
            tmp[tmp_ptr] = 0;
            tmp_ptr = 0; 
        }
        else{
            tmp[tmp_ptr] = bfa_src_code[i];
            tmp_ptr++;
        }
        
    }


}



int main(){
    //Note: Everything will use 32 bits because 64 bit is evil.
    //(and makes funny bugs if anything is larger than 32 bit integer limit)
    //Too lazy to read a file from argv so we just hardcode it

    //[[ COMPILE ]]
    bfa_compile();

    
    static uint8_t bfa_tape[16 * 1024]; //16KB, static to allocate in data section (Stack evil)

    uint32_t bfa_instruction_pointer = 0; //Basically program counter
    uint32_t bfa_data_pointer = 0; //Um i guess just buffer pointer or something

    //Start interpreting.

    while(1){
        switch(bfa_output_code[bfa_instruction_pointer]){
            default: break; //Do nothing, ignored
            case 0: bfa_tape[bfa_data_pointer]++; break;
            case 1: bfa_tape[bfa_data_pointer]--; break;
            case 2: bfa_data_pointer++; break;
            case 3: bfa_data_pointer--; break;
            case 4: putchar(bfa_tape[bfa_data_pointer]); break;
            case 5: bfa_tape[bfa_data_pointer] = getchar(); break;
            //[[ Slightly more complex ones here ]]
            case 6: {
                if(bfa_tape[bfa_data_pointer] == 0){

                    while(bfa_output_code[bfa_instruction_pointer] != 7){
                        bfa_instruction_pointer++;



                    }
                    bfa_instruction_pointer--;

                }

            } break;
            case 7: {
                if(bfa_tape[bfa_data_pointer] != 0){

                    while(bfa_output_code[bfa_instruction_pointer] != 6){
                        bfa_instruction_pointer--;



                    }
                    bfa_instruction_pointer--;

                }

            } break;

        }
        bfa_instruction_pointer++;
    }







    return 0;







}







