/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:28:28 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/27 13:28:12 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

int main(void)
{
	Account		acc1(42);
	Account		acc2(75);
	Account::displayAccountsInfos();
	acc1.displayStatus();
	acc2.displayStatus();
	acc1.makeDeposit(5);
	acc2.makeDeposit(5);
	acc1.makeWithdrawal(47);
	acc2.makeWithdrawal(50);
	acc1.displayStatus();
	acc2.displayStatus();
	Account::displayAccountsInfos();
	return (0);
}