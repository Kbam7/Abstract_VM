/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Abstract_VM.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbam7 <kbam7@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 15:59:16 by kbam7             #+#    #+#             */
/*   Updated: 2017/07/22 07:38:35 by kbam7            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Abstract_VM.hpp"

Abstract_VM::Abstract_VM()
{
    this->inputController = new InputController(this->instruction_list);

    operandCreationFuncs[0] = &Abstract_VM::createInt8;
    operandCreationFuncs[1] = &Abstract_VM::createInt16;
    operandCreationFuncs[2] = &Abstract_VM::createInt32;
    operandCreationFuncs[3] = &Abstract_VM::createFloat;
    operandCreationFuncs[4] = &Abstract_VM::createDouble;
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

IOperand const * Abstract_VM::createOperand( eOperandType type, std::string const & value ) const
{
    return ((this->*operandCreationFuncs[type])(value));
}

IOperand const * Abstract_VM::createInt8( std::string const & value ) const
{
    std::cout << "createInt8( " << value << " )" << std::endl;
    return ( new Operand(AVM_INT8, value) );
}

IOperand const * Abstract_VM::createInt16( std::string const & value ) const
{
    std::cout << "createInt16( " << value << " )" << std::endl;
    return ( new Operand(AVM_INT16, value) );
}

IOperand const * Abstract_VM::createInt32( std::string const & value ) const
{
    std::cout << "createInt32( " << value << " )" << std::endl;
    return ( new Operand(AVM_INT32, value) );
}

IOperand const * Abstract_VM::createFloat( std::string const & value ) const
{
    std::cout << "createFloat( " << value << " )" << std::endl;
    return ( new Operand(AVM_FLOAT, value) );
}

IOperand const * Abstract_VM::createDouble( std::string const & value ) const
{
    std::cout << "createDouble( " << value << " )" << std::endl;
    return ( new Operand(AVM_DOUBLE, value) );
}