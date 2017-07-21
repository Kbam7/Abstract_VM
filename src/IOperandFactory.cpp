/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IOperandFactory.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbam7 <kbam7@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 16:56:19 by kbam7             #+#    #+#             */
/*   Updated: 2017/07/21 08:02:24 by kbam7            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IOperandFactory.hpp"

typedef IOperand const *(OperandFactory::t_operandFactory)(std::string const & value) const;

IOperand const * OperandFactory::createOperand( eOperandType type, std::string const & value ) const
{
    // Add this to global object if possible
    t_operandFactory    *operandFuncs[5] = { &OperandFactory::createInt8,
                                            &OperandFactory::createInt16,
                                            &OperandFactory::createInt32,
                                            &OperandFactory::createFloat,
                                            &OperandFactory::createDouble
                                        };

    return ( (*operandFuncs[type])(value) );

}

IOperand const * OperandFactory::createInt8( std::string const & value ) const
{
    std::cout << "createInt8( " << value << " )" << std::endl;
    return ( new Operand_Int8(value) );
}

IOperand const * OperandFactory::createInt16( std::string const & value ) const
{
    std::cout << "createInt16( " << value << " )" << std::endl;
    return ( new Operand_Int16(value) );
}

IOperand const * OperandFactory::createInt32( std::string const & value ) const
{
    std::cout << "createInt32( " << value << " )" << std::endl;
    return ( new Operand_Int32(value) );
}

IOperand const * OperandFactory::createFloat( std::string const & value ) const
{
    std::cout << "createFloat( " << value << " )" << std::endl;
    return ( new Operand_Float(value) );
}

IOperand const * OperandFactory::createDouble( std::string const & value ) const
{
    std::cout << "createDouble( " << value << " )" << std::endl;
    return ( new Operand_Double(value) );
}