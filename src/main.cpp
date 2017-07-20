/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbam7 <kbam7@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 18:40:21 by kbam7             #+#    #+#             */
/*   Updated: 2017/07/19 23:51:03 by kbam7            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "avm.hpp"

int     main(int argc, char **argv)
{
    Abstract_VM *avm;
    char        *path;

    path = NULL;
    avm = new Abstract_VM();
    if (argc > 1)
    {
        if (avm->getInputFileDescriptor(argv[1]) ==  EXIT_FAILURE)
            return (EXIT_SUCCESS);
    }
    else
        avm->inputFile = stdin;

    if (avm->inputFile == stdin)
        avm->readFromStdin();
    else
        avm->readFromFile();

    avm->run_instructions();

    return (0);
}