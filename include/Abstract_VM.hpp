/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Abstract_VM.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbamping <kbamping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 16:54:03 by kbam7             #+#    #+#             */
/*   Updated: 2017/07/22 17:48:33 by kbamping         ###   ########.fr       */
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

# include "Operand.hpp"
# include "InputHandler.hpp"

class Abstract_VM
{
    public:
        typedef IOperand const *(Abstract_VM::*t_operandFactory)(std::string const &) const;
        
        Abstract_VM(void);
        ~Abstract_VM(void);
        Abstract_VM(Abstract_VM const & src);
        Abstract_VM & operator=(Abstract_VM const & rhs);

        InputHandler                *InputHandler;
        std::list<t_instruction>    instruction_list;
        std::list<const IOperand *> avm_stack;
        t_operandFactory            operandCreationFuncs[5];

        int                 run_instructions(void);
        /*(push|pop|dump|assert|add|sub|mul|div|mod|print|exit)*/
        void                push(IOperand const *val);
        void                pop(void);
        void                dump(void);
        void                assert(IOperand const *val);
        void                add(void);
        void                sub(void);
        void                mul(void);
        void                div(void);
        void                mod(void);
        void                print(void);

        IOperand const *    createOperand( eOperandType type, std::string const & value ) const;
    
    private:
        IOperand const *    createInt8( std::string const & value ) const;
        IOperand const *    createInt16( std::string const & value ) const;
        IOperand const *    createInt32( std::string const & value ) const;
        IOperand const *    createFloat( std::string const & value ) const;
        IOperand const *    createDouble( std::string const & value ) const;


};

#endif /* ABSTRACT_VM_HPP */