/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IOperandFactory.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbam7 <kbam7@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 16:58:44 by kbam7             #+#    #+#             */
/*   Updated: 2017/07/20 16:09:46 by kbam7            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IOPERAND_FACTORY_HPP
# define IOPERAND_FACTORY_HPP

# include "IOperand.hpp"
# include <iostream>

class OperandFactory
{
    public:
        IOperand const * createOperand( eOperandType type, std::string const & value ) const;
        IOperand const * createInt8( std::string const & value ) const;
        IOperand const * createInt16( std::string const & value ) const;
        IOperand const * createInt32( std::string const & value ) const;
        IOperand const * createFloat( std::string const & value ) const;
        IOperand const * createDouble( std::string const & value ) const;
};

#endif /* IOPERAND_FACTORY_HPP */