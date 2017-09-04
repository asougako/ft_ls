

#include "ft_ls.h"

#define pf(VAR, TYPE) printf(#VAR" = %"#TYPE"\n", VAR)
#define content (t_file_infos*)(*link).content
#define file_name (*content).name
//#define file_name (*(*content).dir).d_name
#define file_type (*(*content).dir).d_type
#define file_print  (*content).printable

t_file_infos    **tab_names(t_list *head)
{
        int             index;
        t_list          *link;
        t_file_infos    **names;

        link = head;
        index = 0;
        while(link != NULL)
        {
                if (file_print == true)
                {
                        index++;
                }
                link = (*link).next;
        }
        names = (t_file_infos**)ft_memalloc((index + 1) * sizeof(*names));

        link = head;
        index = 0;
        while(link != NULL)
        {
                if (file_print == true)
                {
                        *(names + index) = content;
                        index++;
                }
                link = (*link).next;
        }
        return(names);
}

#define TAB_LEN (*tab_format).tab_len
#define COLS    (*tab_format).columns
#define LINES   (*tab_format).lines
#define COLWIDTH    (*tab_format).col_width
#define tab_file_name_len (*(*(names + line_index + (col_index * (LINES))))).name_len
uint32_t    line_len(t_tab_format *tab_format, t_file_infos **names)
{
        uint32_t    col_index;
        uint32_t    line_index;

        if (COLWIDTH != NULL)
                ft_memdel((void**)&(COLWIDTH));
        COLWIDTH = (int*)ft_memalloc(COLS * sizeof(*COLWIDTH));

        line_index = 0;
        while (line_index < LINES)
        {
                col_index = 0;
                while (col_index < COLS)
                {
                        if ((line_index + (col_index * (LINES))) >= TAB_LEN)
                        {
                                break;
                        }
                        if ( tab_file_name_len > *(COLWIDTH + col_index))
                        {
                                *(COLWIDTH + col_index) = (tab_file_name_len + 0);
                        }
                        col_index++;
                }
                line_index++;
        }

        uint32_t temp = 0;
        uint32_t sum = 0;
        while (temp < COLS)
        {
                *(COLWIDTH + temp) += 2;
                sum += *(COLWIDTH + temp);
                temp++;
        }
        return(sum - 2);
}
t_tab_format    *how_much_cols(t_file_infos **names)
{
        struct          winsize w;
        t_tab_format    *tab_format;


        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
        tab_format = (t_tab_format*)ft_memalloc(sizeof(*tab_format));
        TAB_LEN = ft_strtab_len((char **)names);
        COLS = 2;
        LINES = (((TAB_LEN - 1) / COLS) + 1);
		if (!(opt & opt_1))
		{
				while (line_len(tab_format, names) < w.ws_col)
				{
						COLS++;
						LINES = (((TAB_LEN - 1) / COLS) + 1);
				}
		}
		COLS--;
		LINES = (((TAB_LEN - 1) / COLS) + 1);
        line_len(tab_format, names);
        return(tab_format);
}

#define tab_file_name (*(*(*(names + line_index + (col_index * (LINES))))).dir).d_name
void    print_dir_short(t_list *head)
{
        t_file_infos    **names;
        t_tab_format    *tab_format;
        uint32_t        line_index;
        uint32_t        col_index;

        int padding;

        //tab of names
        names = tab_names(head);
		if (*names == NULL)		//nothing to print
				return;
        //format
        tab_format = how_much_cols(names);
        //print
        line_index = 0;
        while (line_index < LINES)
        {
                col_index = 0;
                while (col_index < COLS)
                {
                        if ((line_index + (col_index * (LINES))) >= TAB_LEN)
                                break;
                        ft_putstr(tab_file_name );
                        //padding
                        padding = 0;
                        if (col_index < COLS - 1)
                        {
                                while((ft_strlen(tab_file_name) + padding) < (*(COLWIDTH + col_index) + 0))
                                {
                                        ft_putstr(" ");
                                        padding++;
                                }
                        }
                        col_index++;
                }
                ft_putendl("");
                line_index++;
        }
}
#undef TAB_LEN
#undef COLS
#undef LINES
#undef COLWIDTH
#undef tab_file_name_len
#undef tab_file_name
