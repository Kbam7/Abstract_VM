/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Abstract_VM.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbam7 <kbam7@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 15:59:16 by kbam7             #+#    #+#             */
/*   Updated: 2017/07/20 15:17:50 by kbam7            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Abstract_VM.hpp"

Abstract_VM::Abstract_VM()
{
    this->inputController = new InputController(this->instruction_list);
}

Abstract_VM::~Abstract_VM(void)
{
    if (this->inputController)
        delete this->inputController;
}

Abstract_VM::Abstract_VM(Abstract_VM const & src)
{
    *this = src;
}

Abstract_VM & Abstract_VM::operator=(Abstract_VM const & rhs)
{
    this->instruction_list = rhs.instruction_list;

    return (*this);
}

int             Abstract_VM::run_instructions(void)
{
    int             n = 1;
    t_instruction   x;

    for (t_instruction y : this->instruction_list)
    {
        if (!y.valid)
            return (EXIT_FAILURE);
    }

    while (!this->instruction_list.empty())
    {
        x = this->instruction_list.front();
        std::cout << "--------------------" << std::endl;
        std::cout << "Item " << n << std::endl;

        std::cout << "VALID: " << ((x.valid) ? "true" : "false") << std::endl;
        std::cout << "LINE: " << x.line << std::endl;
        std::cout << "LINE_NR: " << x.line_nr << std::endl;
        std::cout << "COMMAND: " << x.command << std::endl;
        std::cout << "OPERAND TYPE: " << x.operandType << std::endl;
        std::cout << "VALUE: " << x.value << std::endl;

        std::cout << "--------------------" << std::endl << std::endl;
        
        this->instruction_list.pop_front();
        ++n;
    }
    return (EXIT_SUCCESS);
}