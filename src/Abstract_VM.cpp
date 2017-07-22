/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Abstract_VM.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbamping <kbamping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 15:59:16 by kbam7             #+#    #+#             */
/*   Updated: 2017/07/22 18:31:02 by kbamping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Abstract_VM.hpp"
#include <cstdlib>

Abstract_VM::Abstract_VM()
{
    this->InputHandler = new InputHandler::InputHandler(this->instruction_list);

    operandCreationFuncs[0] = &Abstract_VM::createInt8;
    operandCreationFuncs[1] = &Abstract_VM::createInt16;
    operandCreationFuncs[2] = &Abstract_VM::createInt32;
    operandCreationFuncs[3] = &Abstract_VM::createFloat;
    operandCreationFuncs[4] = &Abstract_VM::createDouble;
}

Abstract_VM::~Abstract_VM(void)
{
    if (this->InputHandler)
        delete this->InputHandler;
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
/*         std::cout << "--------------------" << std::endl;
        std::cout << "Item " << n << std::endl;

        std::cout << "VALID: " << ((x.valid) ? "true" : "false") << std::endl;
        std::cout << "LINE: " << x.line << std::endl;
        std::cout << "LINE_NR: " << x.line_nr << std::endl;
        std::cout << "COMMAND: " << x.command << std::endl;
        std::cout << "OPERAND TYPE: " << x.operandType << std::endl;
        std::cout << "VALUE: " << x.value << std::endl;

        std::cout << "--------------------" << std::endl << std::endl; */

        try
        {
            switch (x.command)
            {
                    case CMD_PUSH:
                        std::cout << "PUSHING" << std::endl; // debug
                        this->push(createOperand(x.operandType, x.value));
                        break;
                    case CMD_POP:
                        std::cout << "POPPING" << std::endl; // debug
                        this->pop();
                        break;
                    case CMD_DUMP:
                        std::cout << "PUSHING" << std::endl; // debug
                        this->dump();
                        break;
                    case CMD_ASSERT:
                        std::cout << "ASSERTING" << std::endl; // debug
                        this->assert(createOperand(x.operandType, x.value));
                        break;
                    case CMD_ADD:
                        std::cout << "ADDING" << std::endl; // debug
                        this->add();
                        break;
                    case CMD_SUB:
                        std::cout << "SUBBING" << std::endl; // debug
                        this->sub();
                        break;
                    case CMD_MUL:
                        std::cout << "MULTIPLYING" << std::endl; // debug
                        this->mul();
                        break;
                    case CMD_DIV:
                        std::cout << "DIVIDING" << std::endl; // debug
                        this->div();
                        break;
                    case CMD_MOD:
                        std::cout << "MODULUSING" << std::endl; // debug
                        this->mod();
                        break;
                    case CMD_PRINT:
                        std::cout << "PRINTING" << std::endl; // debug
                        this->print();
                        break;
                    case CMD_EXIT:
                        std::cout << "EXITING" << std::endl; // debug
                        break;
                    case CMD_NONE:
                    default:
                        break;
            }
        } catch (std::exception & e)
        {
            std::cerr << C_BOLD << C_RED << "ERROR: " << C_NONE << C_BOLD << "Line: " << x.line_nr << " --> "
                << e.what() << C_NONE << " '" << x.line << "'" << std::endl;
        }
        
        this->instruction_list.pop_front();
        ++n;
        std::cout << std::endl << std::endl; // debug
    }
    return (EXIT_SUCCESS);
}

void                Abstract_VM::push(IOperand const *val)
{
    this->avm_stack.push_front(val);
}

void                Abstract_VM::pop(void)
{
    if (this->avm_stack.empty())
        throw AVM_Exception("Pop on empty stack");
    this->avm_stack.pop_front();
}

void                Abstract_VM::dump(void)
{
    if (this->avm_stack.empty())
        throw AVM_Exception("Dump on empty stack");

    for (std::list<const IOperand *>::iterator it = this->avm_stack.begin(); it != this->avm_stack.end(); ++it)
        std::cout << (*it)->toString() << std::endl;
}

void                Abstract_VM::assert(IOperand const *val)
{
    double  tmp1;
    double  tmp2;

    if (this->avm_stack.empty())
        throw AVM_Exception("Assert on empty stack");

    tmp1 = stod(this->avm_stack.front()->toString());
    tmp2 = stod(val->toString());
    if (tmp1 != tmp2)
        throw AVM_Exception("Assert failed");
}

void                Abstract_VM::add(void)
{
    const IOperand *tmp1;
    const IOperand *tmp2;

    if (this->avm_stack.size() < 2)
        throw AVM_Exception("Add failed - Not enough operands on stack");
    
    tmp1 = this->avm_stack.front();
    this->avm_stack.pop_front();

    tmp2 = this->avm_stack.front();
    this->avm_stack.pop_front();

    this->avm_stack.push_front(*tmp1 + *tmp2);
}

void                Abstract_VM::sub(void)
{
    const IOperand *tmp1;
    const IOperand *tmp2;

    if (this->avm_stack.size() < 2)
        throw AVM_Exception("Sub failed - Not enough operands on stack");
    
    tmp1 = this->avm_stack.front();
    this->avm_stack.pop_front();

    tmp2 = this->avm_stack.front();
    this->avm_stack.pop_front();

    this->avm_stack.push_front(*tmp1 - *tmp2);
}

void                Abstract_VM::mul(void)
{
    const IOperand *tmp1;
    const IOperand *tmp2;

    if (this->avm_stack.size() < 2)
        throw AVM_Exception("Mul failed - Not enough operands on stack");
    
    tmp1 = this->avm_stack.front();
    this->avm_stack.pop_front();

    tmp2 = this->avm_stack.front();
    this->avm_stack.pop_front();

    this->avm_stack.push_front(*tmp1 * *tmp2);
}

void                Abstract_VM::div(void)
{
    const IOperand *tmp1;
    const IOperand *tmp2;

    if (this->avm_stack.size() < 2)
        throw AVM_Exception("Div failed - Not enough operands on stack");
    
    tmp1 = this->avm_stack.front();
    this->avm_stack.pop_front();

    tmp2 = this->avm_stack.front();
    this->avm_stack.pop_front();

    this->avm_stack.push_front(*tmp1 / *tmp2);
}

void                Abstract_VM::mod(void)
{
    const IOperand *tmp1;
    const IOperand *tmp2;

    if (this->avm_stack.size() < 2)
        throw AVM_Exception("Mod failed - Not enough operands on stack");
    
    tmp1 = this->avm_stack.front();
    this->avm_stack.pop_front();

    tmp2 = this->avm_stack.front();
    this->avm_stack.pop_front();

    this->avm_stack.push_front(*tmp1 + *tmp2);
}
void                Abstract_VM::print(void)
{
    const IOperand *tmp1;

    if (this->avm_stack.front()->getType() != AVM_INT8)
        throw AVM_Exception("Print failed - Top value not int8 type");

    tmp1 = this->avm_stack.front();
    std::cout << stoi(tmp1->toString());
}

IOperand const * Abstract_VM::createOperand( eOperandType type, std::string const & value ) const
{
    return ((this->*operandCreationFuncs[type])(value));
}

IOperand const * Abstract_VM::createInt8( std::string const & value ) const
{
    std::cout << "createInt8( " << value << " )" << std::endl;
    return ( new Operand<char>(AVM_INT8, strtod(value.c_str(), NULL)));
}

IOperand const * Abstract_VM::createInt16( std::string const & value ) const
{
    std::cout << "createInt16( " << value << " )" << std::endl;
    return ( new Operand<short>(AVM_INT16, stod(value)) );
}

IOperand const * Abstract_VM::createInt32( std::string const & value ) const
{
    std::cout << "createInt32( " << value << " )" << std::endl;
    return ( new Operand<int>(AVM_INT32, stod(value)) );
}

IOperand const * Abstract_VM::createFloat( std::string const & value ) const
{
    std::cout << "createFloat( " << value << " )" << std::endl;
    return ( new Operand<float>(AVM_FLOAT, stod(value)) );
}

IOperand const * Abstract_VM::createDouble( std::string const & value ) const
{
    std::cout << "createDouble( " << value << " )" << std::endl;
    return ( new Operand<double>(AVM_DOUBLE, stod(value)) );
}