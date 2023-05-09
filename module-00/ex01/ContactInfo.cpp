/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ContactInfo.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tim-rdt <root@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 15:41:37 by tim-rdt           #+#    #+#             */
/*   Updated: 2023/04/16 15:59:45 by tim-rdt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ContactInfo.hpp"

ContactInfo::ContactInfo( std::string name, std::string surname, std::string nickname, std::string number, std::string secret ) {

	this->name = name;
	this->surname = surname;
	this->nickname = nickname;
	this->number = number;
	this->secret = secret;

}