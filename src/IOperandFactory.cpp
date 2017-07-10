/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IOperandFactory.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbam7 <kbam7@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 16:56:19 by kbam7             #+#    #+#             */
/*   Updated: 2017/07/05 18:04:42 by kbam7            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IOperandFactory.hpp"

enum eOperandType
{
    AVM_INT_8 = 0,
    AVM_INT_16,
    AVM_INT_32,
    AVM_FLOAT,
    AVM_DOUBLE
}

IOperand const * createOperand( eOperandType type, std::string const & value ) const
{
    // Add this to global object if possible
    t_operandFactory    operandFuncs[5] = { &createInt8, &createInt16, &createInt32, &createFloat, &createDouble };

    return ( operandFuncs[type](value) );

}

IOperand const * createInt8( std::string const & value ) const
{
    std::cout << "createInt8( " << value << " )" << std::endl;
    return ( new Operand_Int8(value) );
}

IOperand const * createInt16( std::string const & value ) const
{
    std::cout << "createInt16( " << value << " )" << std::endl;
    return ( new Operand_Int16(value) );
}

IOperand const * createInt32( std::string const & value ) const
{
    std::cout << "createInt32( " << value << " )" << std::endl;
    return ( new Operand_Int32(value) );
}

IOperand const * createFloat( std::string const & value ) const
{
    std::cout << "createFloat( " << value << " )" << std::endl;
    return ( new Operand_Float(value) );
}

IOperand const * createDouble( std::string const & value ) const
{
    std::cout << "createDouble( " << value << " )" << std::endl;
    return ( new Operand_Double(value) );
}