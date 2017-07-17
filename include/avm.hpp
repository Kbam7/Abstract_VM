/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avm.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbamping <kbamping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 16:54:03 by kbam7             #+#    #+#             */
/*   Updated: 2017/07/17 14:07:28 by kbamping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVM_HPP
# define AVM_HPP

#include <cstdio> // File I/O
#include <iostream>
#include <string>
#include <cstring>

//#include "IOperandFactory.hpp"

typedef struct  s_instruction
{
    std::string command;
    std::string operandType;
    std::string value;
    bool        valid;
    std::string line;
}               t_instruction;

#endif /* AVM_HPP */