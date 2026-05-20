/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 14:04:47 by akolupae          #+#    #+#             */
/*   Updated: 2026/05/20 19:27:45 by akolupae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

struct Data {

public:

	Data(void) : Data(0) {};
	Data(int val) : _value(val) {};
	Data(const Data& other);
	Data(Data&& other) noexcept = default;
	Data&	operator= (const Data& other);
	Data&	operator= (Data&& other) noexcept = default;
	~Data(void) {};

	const int&	getValue() const;
	void		setValue(int val);

private:

	int		_value;
};
