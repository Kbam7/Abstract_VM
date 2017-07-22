/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AVM_Exception.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbamping <kbamping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 15:18:16 by kbamping          #+#    #+#             */
/*   Updated: 2017/07/22 15:22:00 by kbamping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVM_EXCEPTION_HPP
# define AVM_EXCEPTION_HPP

# include <exception>

class AVM_Exception : public std::exception
{
    public:
        AVM_Exception(char *error) throw();
        virtual ~AVM_Exception() throw();
        AVM_Exception(AVM_Exception const & src);
        AVM_Exception & operator=(AVM_Exception const & rhs);

        virtual const char* what() const throw();

    private:
        char  *_errorMsg;
};

#endif /* AVM_EXCEPTION_HPP */