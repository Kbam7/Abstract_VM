/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Abstract_VM.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbam7 <kbam7@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 16:54:03 by kbam7             #+#    #+#             */
/*   Updated: 2017/07/19 23:01:05 by kbam7            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACT_VM_HPP
# define ABSTRACT_VM_HPP

# include <cstdio> // File I/O
# include <iostream>
# include <string>
# include <cstring>
# include <regex>
# include <list>
# include <stack>
# include <exception>

# include "IOperandFactory.hpp"
# include "InputController.hpp"

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

class Abstract_VM
{
    public:
        Abstract_VM(void);
        ~Abstract_VM(void);
        Abstract_VM(Abstract_VM const & src);
        Abstract_VM & operator=(Abstract_VM const & rhs);

        int             run_instructions(void);

        InputController             *inputController;
        std::list<t_instruction>    instruction_list;
        std::stack<IOperand *>      avm_stack;


};

#endif /* ABSTRACT_VM_HPP */