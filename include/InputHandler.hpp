/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InputHandler.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbamping <kbamping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 22:21:33 by kbam7             #+#    #+#             */
/*   Updated: 2017/07/22 12:38:04 by kbamping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_CONTROLLER_HPP
# define INPUT_CONTROLLER_HPP

# include <cstdio> // File I/O
# include <iostream>
# include <string>
# include <cstring>
# include <regex>
# include <list>
# include <stack>
# include <exception>

# include "IOperand.hpp"

# ifndef AVM_COLOURS
#  define AVM_COLOURS
#  define C_NONE         "\033[0m"
#  define C_BOLD         "\033[1m"
#  define C_BLACK        "\033[30m"
#  define C_RED          "\033[31m"
#  define C_GREEN        "\033[32m"
#  define C_BROWN        "\033[33m"
#  define C_BLUE         "\033[34m"
#  define C_MAGENTA      "\033[35m"
#  define C_CYAN         "\033[36m"
#  define C_GRAY         "\033[37m"
# endif /* AVM_COLOURS */

typedef enum  e_command
{
    CMD_NONE = 0,
    CMD_PUSH,
    CMD_POP,
    CMD_DUMP,
    CMD_ASSERT,
    CMD_ADD,
    CMD_SUB,
    CMD_MUL,
    CMD_DIV,
    CMD_MOD,
    CMD_PRINT,
    CMD_EXIT
}               t_command;

typedef struct  s_instruction
{
    bool            valid;
    std::string     line;
    unsigned int    line_nr;
    t_command       command;
    eOperandType    operandType;
    std::string     value;
}               t_instruction;

class InputHandler
{
    public:
        InputHandler(std::list<t_instruction> & instruction_list);
        ~InputHandler(void);
        InputHandler(InputHandler const & src);
        InputHandler & operator=(InputHandler const & rhs);

        const size_t                maxStrSize = 1024;
        FILE                        *inputFile;
        std::list<t_instruction>    instruction_list;

        int             getInputFileDescriptor(char *filepath);
        int             readFromStdin(void);
        int             readFromFile(void);
        char            *tokenize_line(char *line);
        t_command       get_command(char *cmd);
        eOperandType    get_operandType(std::string str);
        t_instruction   parser(char *line, int n_line);
        void            parse_token(char *token, t_instruction *currInstruction);

        class UnrecognisedToken: public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class InputFileError: public std::exception {
            public:
                virtual const char* what() const throw();
        };

};

#endif /* INPUT_CONTROLLER_HPP */