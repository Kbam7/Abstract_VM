/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbam7 <kbam7@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 18:40:21 by kbam7             #+#    #+#             */
/*   Updated: 2017/07/17 09:43:22 by kbam7            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "avm.hpp"
#include <regex>
#include <list>

t_instruction   lexical_analysis(char *line);
int             handleFileInput(char *filepath, std::list<t_instruction> & list);

int     main(int argc, char **argv)
{
    std::list<t_instruction>    lexed_input;

    if (argc > 1) {
        // handle file input
        if (handleFileInput(argv[1], lexed_input) ==  EXIT_FAILURE)
            return (EXIT_FAILURE);
    }
    else {
        // read from stdin`
        // tokenize input (lexer)
    }

    int n = 1;
    for (t_instruction x : lexed_input)
    {
        std::cout << "--------------------" << std::endl;
        std::cout << "Item " << n << std::endl;

        std::cout << "COMMAND: " << x.command << std::endl;
        std::cout << "DATATYPE: " << x.operandType << std::endl;
        std::cout << "VALUE: " << x.value << std::endl;

        std::cout << "--------------------" << std::endl << std::endl;;
        ++n;
    }


        // run instructions (parse)
        
        //      INTS
        //-- CHECK for overflow of SCHAR_MIN, SCHAR_MAX, SHRT_MIN, SHRT_MAX, LONG_MIN, LONG_MAX ----- #include <climits>
        // int8 max == 127
        // int16 max == 32767
        // int32 max == 2147483647

        //      FLOATING POINT
        // -- CHECK for overflow of FLT_MIN, FLT_MAX, DBL_MIN, DBL_MAX  ----- #include <cfloat>


    return (0);
}

int     handleFileInput(char *filepath, std::list<t_instruction> & list)
{
    const size_t                maxStrSize = 1024;
    char                        buf[maxStrSize];
    FILE                        *inputFile;
    
    // open file
    if (!(inputFile = fopen(filepath, "r"))) {
        std::cout << "ERROR: Unable to open file! 'filepath'\n"
                << "Would you like to get input from the keyboard instead? [y/n]" << std::endl;
        std::cin >> buf;
        while (*buf)
        {
            if (*buf == 'y' || *buf == 'Y' || *buf == '\n')
            {
                std::cout << "Read from keyboard" << std::endl;
                // read from stdin
                // tokenize input (lexer)
                break;
            } else if (*buf == 'n' || *buf == 'N') {
                std::cout << "Dont Read from keyboard" << std::endl;
                break;
            }
            else
                std::cin >> buf;
        }
        return (EXIT_FAILURE);
    }

    // Read from file and return list of instructions
    while (fgets(buf, maxStrSize, inputFile))
    {
        // Comment or empty line
        if (*buf == ';' || *buf == '\n')
            continue;

        // Add new instruction
        list.push_back( lexical_analysis(buf) );
    }
    return (EXIT_SUCCESS);
}

t_instruction   lexical_analysis(char *line)
{
    std::regex      avm_commands("(push|pop|dump|assert|add|sub|mul|div|mod|print|exit)"); /* (push|assert)( |\t)+(int(8|16|32)|float|double)\([0-9]+((.)*([0-9]+))?\) */
    std::regex      avm_dataTypes("(int(8|16|32)|float|double)\\(([0-9]+((.)*([0-9]+))?)\\)");
    t_instruction   currInstruction;
    char            *token;
    std::cmatch     cm;

    std::cout << "---" << line << "--- "; // debug

    // tokenize line
    token = strtok(line, " \n");
    while (token)
    {
        std::cout << ">" << token << "< "; // debug

        if (std::regex_match (token, avm_commands))
        {
                std::cout << "token is a command";
                currInstruction.command = token;
        }
        else if (std::regex_match (token, avm_dataTypes))
        {
            std::cout << "token is a dataType";
            // get data type and value from token
            //currInstruction.operandType = strtok(token, "()");
            //currInstruction.value = strtok(NULL, "()");

            std::regex_match (token, cm, avm_dataTypes);
            std::cout << "-- The matches were: ";
            for (unsigned i=0; i<cm.size(); ++i) {
                std::cout << "[" << cm[i] << "] ";
            }

            std::cout << std::endl;

            currInstruction.operandType = cm[1];
            currInstruction.value = cm[3];

        }

        std::cout << std::endl;
        // 
        token = strtok(NULL, " \n");
    }
    return (currInstruction);
}