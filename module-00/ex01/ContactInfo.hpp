/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ContactInfo.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tim-rdt <root@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 15:39:46 by tim-rdt           #+#    #+#             */
/*   Updated: 2023/04/16 18:29:53 by tim-rdt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class ContactInfo {

	public:
		ContactInfo() {};
		ContactInfo( std::string name, std::string surname, std::string nickname, std::string number, std::string secret );
		~ContactInfo() {};

		std::string	name;
		std::string	surname;
		std::string	nickname;
		std::string	number;
		std::string	secret;
};