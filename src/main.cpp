/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbam7 <kbam7@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 18:40:21 by kbam7             #+#    #+#             */
/*   Updated: 2017/07/13 08:26:48 by kbam7            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdio> // File I/O
#include <iostream>
#include <string>
//#include "IOperandFactory.hpp"

int     main(int argc, char **argv)
{
    const size_t    maxStrSize = 1024;
    FILE            *inputFile;
    char            buf[maxStrSize];
    char            *token;

    if (argc > 1) {
        // open file
        if (!(inputFile = fopen(argv[1], "r"))) {
            std::cout << "ERROR: Unable to open file! Would you like to get input from the keyboard instead? [y/n]" << std::endl;
            std::cin >> buf;
            while (*buf)
            {
                if (*buf == 'y' || *buf == 'Y' || *buf == '\n')
                {
                    std::cout << "Read from keyboard" << std::endl;
                    // read from stdin
                    // tokenize input (lexer)
                    break;
                } else if (*buf == 'n' || *buf == 'N') {
                    std::cout << "Dont Read from keyboard" << std::endl;
                    break;
                }
                else
                    std::cin >> buf;
            }
            return (0);
        }
        while (fgets(buf, maxStrSize, inputFile))
        {
            if (*buf == ';')
            {
                //std::cout << "comment" << std::endl;
                continue;
            }
            std::cout << buf;
            // tokenize input (lexer)
            

            // run instructions (parse)
        }
        
    }
    else {
        // read from stdin
        // tokenize input (lexer)
    }

    return (0);
}