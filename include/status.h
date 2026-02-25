/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigarashi <tigarashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 13:31:20 by itakumi           #+#    #+#             */
/*   Updated: 2026/02/25 13:41:50 by tigarashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATUS_H
# define STATUS_H

/**
 * @enum t_status
 * This enumeration was created to provide a clear indication 
 * of the success or failure of a function.
 */
typedef enum e_status
{
	STATUS_OK = 0,
	STATUS_ERROR = -1
}	t_status;

#endif
