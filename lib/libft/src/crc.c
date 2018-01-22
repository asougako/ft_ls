/*
 *	Cyclic Redundancy Check witch touch the sky!
 */

#define byte char
uint8_t			*ft_crc(uint8_t *polynome, uint8_t *message, int32_t polynome_size, int32_t message_size)
{
		uint8_t	*ret = NULL;
		uint8_t	buffer [message_size + 1];
		int32_t	polynome_byte_size = (polynome_size + 7) / 8;
		int32_t	polynome_start_addr = (message_size + 1) - polynome_byte_size;

		for (int byte_index = 0; byte_index < message_size + 1; byte_index++)	//cpy message in buffer
				*(buffer + byte_index) = *(message + byte_index);
		for (int byte_index = 0; byte_index < (message_size * 8) + ((polynome_size - 1) % 8); byte_index++)
		{
				shift_seq(buffer, message_size + 1);		//shift buffer
				if ((*(buffer + message_size) & 1u << (((polynome_size - 1) % 8))) != 0)	//need to xor?
						for(int polynome_index = 0; polynome_index < polynome_byte_size; polynome_index++)	//xor
								*(buffer + ((message_size + 1) - polynome_byte_size) + polynome_index) ^= *(polynome + polynome_index);
		}
		ret = (unsigned char *)malloc(sizeof(*ret) * message_size + polynome_byte_size);
		ret = ft_memcpy(ret, buffer + polynome_start_addr, polynome_byte_size);
		return(ret);
}
