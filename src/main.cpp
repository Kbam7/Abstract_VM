/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbamping <kbamping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 18:40:21 by kbam7             #+#    #+#             */
/*   Updated: 2017/07/22 16:22:47 by kbamping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Abstract_VM.hpp"

int     main(int argc, char **argv)
{
    Abstract_VM     *avm;
    InputHandler    *ih;
    char            *path;

    path = NULL;
    avm = new Abstract_VM();
    ih = avm->InputHandler;
    
    if (argc > 1)
    {
        if (ih->getInputFileDescriptor(argv[1]) ==  EXIT_FAILURE)
            return (EXIT_SUCCESS);
    }

    // Read input
    ih->readInputFile();

    avm->run_instructions();

    return (0);
}