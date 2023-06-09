#include <tngmenu.h>
#include <_ui.h>
#include <string.h>
#include <tngfont.h>
#include <barrykey.h>

void tng_menu_ui_display(void *vtng, Rect *r)
{
   TNG *ptng = (TNG *)vtng;
   if ((ptng != NULL) && TNG_MN(ptng)->popped_up)
   {
      Spew(DSRC_UI_Menu, ("Trying to draw the menu...\n"));
      TNG_DRAWRECT(ptng, r);
   }
}

// Initializes the TNG G
errtype tng_menu_init(void *ui_data, TNG *ptng, TNGStyle *sty, Point coord, int width, void (*upfunc)(TNG *ptng),
   void (*downfunc)(TNG *ptng), void *ui_struct)
{
   TNG_menu *pmntng;
   grs_font *f;

   pmntng = (TNG_menu *)GUI_MALLOC(ptng->ui_data, sizeof(TNG_menu));

   TNGInit(ptng,sty,ui_data);
   ptng->flags = TNG_BEVEL;
   ptng->type_data = pmntng;
   ptng->draw_func = &tng_menu_2d_draw;
   ptng->mousebutt = &tng_menu_mousebutt;
   ptng->keycooked = &tng_menu_keycooked;
   ptng->signal = &tng_menu_signal;

   pmntng->tng_data = ptng;
   pmntng->ui_struct = ui_struct;
   pmntng->size.x = width;
   pmntng->size.y = 2;
   pmntng->num_lines = 0;
   pmntng->current_selection = NULL;
   pmntng->popup_func = upfunc;
   pmntng->popdown_func = downfunc;
   pmntng->popped_up = FALSE;
   pmntng->coord = coord;
   llist_init(&(pmntng->element_header));

   f = (grs_font *)ResLock(ptng->style->font);
   pmntng->slot_height = f->h + TNG_MENU_SPACING;
   ResUnlock(ptng->style->font);

   return(OK);
}

// Deallocate all memory used by the TNG 
errtype tng_menu_destroy(TNG *ptng)
{
   MenuElement *pnode,*pnode_next;
   TNG_menu *pmntng;
   pmntng = TNG_MN(ptng);
   pnode = llist_head(&(pmntng->element_header));
   while (pnode != llist_end(&(pmntng->element_header)))
	{
   	pnode_next = llist_next(pnode);
	   llist_remove(pnode);
      Free(pnode);
   	pnode = pnode_next;
	}
   GUI_DEALLOC(ptng->ui_data, ptng->type_data);
   return(OK);
}

// Draw the specified parts (may be all) of the TNG at screen coordinates loc
// assumes all appropriate setup has already been done!
errtype tng_menu_2d_draw(TNG *ptng, ushort partmask, Point loc)
{
   TNG_menu *pmntng;
   int xloc, yloc;
   ushort dummy;
   char lstring[200], *s;

   MenuElement *curp;
   int count = 0;
   dummy = partmask;

   ptng->signal(ptng, TNG_SIGNAL_EXPOSE);
   pmntng = TNG_MN(ptng);
   TNGDrawBase(ptng, loc, pmntng->size);
   xloc = loc.x + 1;
   yloc = loc.y + 1;

   curp = llist_head(&(pmntng->element_header));
   while (count < pmntng->num_lines)
   {
      strcpy(lstring, curp->label);
      if (curp->keycode != 0)
      {
         strcat(lstring, " (");
         if (curp->keycode & KB_FLAG_ALT)
            strcat(lstring, "A-");
         if (curp->keycode & KB_FLAG_CTRL)
            strcat(lstring, "C-");
         if (kb_isupper(curp->keycode))
            strcat(lstring, "S-");
         else
            switch (curp->keycode & 0xFF)
            {
            case (KEY_F1 & 0xFF): strcat(lstring, "F1)");  break;
            case (KEY_F2 & 0xFF): strcat(lstring, "F2)");  break;
            case (KEY_F3 & 0xFF): strcat(lstring, "F3)");  break;
            case (KEY_F4 & 0xFF): strcat(lstring, "F4)");  break;
            case (KEY_F5 & 0xFF): strcat(lstring, "F5)");  break;
            case (KEY_F6 & 0xFF): strcat(lstring, "F6)");  break;
            case (KEY_F7 & 0xFF): strcat(lstring, "F7)");  break;
            case (KEY_F8 & 0xFF): strcat(lstring, "F8)");  break;
            case (KEY_F9 & 0xFF): strcat(lstring, "F9)");  break;
            case (KEY_F10 & 0xFF): strcat(lstring, "F10)");  break;
            case (KEY_F11 & 0xFF): strcat(lstring, "F11)");  break;
            case (KEY_F12 & 0xFF): strcat(lstring, "F12)");  break;
            }
         if (kb_isprint(curp->keycode))
         {
            // Mark's gross algorithm(tm)
            s = lstring;
            while (*s != '\0')
               s++;
            s[0] = curp->keycode;
            s[1] = ')';
            s[2] = '\0';
         }
      }
      if (curp == pmntng->current_selection)
         gr_set_fcolor(ptng->style->altTextColor);
      else
         gr_set_fcolor(ptng->style->textColor);
      TNG_DRAW_TEXT(ptng, lstring, xloc, yloc);
      yloc += pmntng->slot_height;
      curp = llist_next(curp);
      count++;
   }
   if (curp != NULL)
   {
      Spew(DSRC_UI_Menu, ("curp problem in drawing...\n"));
   }

   return(OK);
}

// Fill in ppt with the size...
errtype tng_menu_size(TNG *ptng, Point *ppt)
{
   *ppt = TNG_MN(ptng)->size;
   return(OK);
}

// Returns the current "value" of the TNG
int tng_menu_getvalue(TNG *ptng)
{
   return(TNG_MN(ptng)->num_lines);
}

// React appropriately for receiving the specified cooked key
bool tng_menu_keycooked(TNG *ptng, ushort key)
{
   ushort code = key ^ KB_FLAG_DOWN;
   bool retval = FALSE;
   MenuElement *csel, *next;

   switch(code)
   {
      case KEY_ESC:
         IF_SET_RV(ptng->signal(ptng,TNG_SIGNAL_DESELECT));
         break;
      case KEY_SPACE:
      case KEY_ENTER:
         IF_SET_RV(ptng->signal(ptng,TNG_SIGNAL_SELECT));
         break;
      case TNG_BA_DOWN_KEY:
      case TNG_BA_RIGHT_KEY:
         csel = TNG_MN(ptng)->current_selection;
         if (csel != NULL)
            csel = llist_next(csel);
         if ((csel == NULL) || (csel == llist_end(&(TNG_MN(ptng)->element_header))))
            csel = llist_head(&(TNG_MN(ptng)->element_header));
         TNG_MN(ptng)->current_selection = csel;
         TNG_DRAW(ptng);
         break;
      case TNG_BA_UP_KEY:
      case TNG_BA_LEFT_KEY:
         csel = llist_head(&(TNG_MN(ptng)->element_header));
//         if (csel == TNG_MN(ptng)->current_selection)
//            csel = llist_end(&(TNG_MN(ptng)->element_header));
//         else
//         {
            next = llist_next(csel);
            while ((next != TNG_MN(ptng)->current_selection) && (next != llist_end(&(TNG_MN(ptng)->element_header))))
            {
               csel = next;
               next = llist_next(next);
            }
//         }
         TNG_MN(ptng)->current_selection = csel;
         TNG_DRAW(ptng);
         break;
   }
   retval = TRUE;
   IF_SET_RV(tng_cb_keycooked(ptng, key));
   return(retval);
}

// React appropriately for receiving the specified mouse button event
bool tng_menu_mousebutt(TNG *ptng, uchar type, Point loc)
{
   bool retval = FALSE;
   int localy;
   TNG_menu *pmntng;
   MenuElement *curp;

   if (type == TNG_MOUSE_LDOWN)
   {
      pmntng = TNG_MN(ptng);
      localy = loc.y - 1;
      curp = llist_head(&(pmntng->element_header));
      while ((curp != NULL) && (localy > pmntng->slot_height))
      {
         localy -= pmntng->slot_height;
         curp = llist_next(curp);
      }
      if ((curp != NULL) && (localy <= pmntng->slot_height))
      {
         pmntng->current_selection = curp;
         ptng->signal(ptng, TNG_SIGNAL_SELECT);
      }
      else
         pmntng->current_selection = NULL;
   }
   IF_SET_RV(tng_cb_mousebutt(ptng,type,loc));
   retval = TRUE;
   return(retval);
}

// Handle incoming signals
bool tng_menu_signal(TNG *ptng, ushort signal)
{
   bool retval = FALSE;

   if (signal & TNG_SIGNAL_SELECT)
      IF_SET_RV(tng_menu_selection(ptng));
   if (signal & TNG_SIGNAL_DESELECT)
   {
      retval = TRUE;
      TNG_MN(ptng)->popdown_func(ptng);
   }
   IF_SET_RV(tng_cb_signal(ptng,signal));
   retval = TRUE;
   return(retval);
}

errtype tng_menu_selection(TNG *ptng)
{
   MenuElement *c =  TNG_MN(ptng)->current_selection;

   Spew(DSRC_UI_Menu, ("doing menu_selection...\n"));
   TNG_MN(ptng)->popdown_func(ptng); 
   if (c->submenu == NULL)
   {
      if (c->keycode == 0)
         c->f(c->keycode, c->context, c->user_data);
      else
         hotkey_dispatch(c->keycode);
   }
   else
   {
      tng_menu_popup_at_mouse(c->submenu);
//      TNG_MN(ptng)->popup_func(c->submenu);      
   }
   return(OK);
}

errtype tng_menu_add_line(TNG *ptng, char *label, hotkey_callback f, short keycode, ulong context,
   void *user_data, char *help_text)
{
   MenuElement *newelem;

   newelem = tng_menu_add_basic(ptng, label);
   if (keycode != 0)
      hotkey_add_help(keycode,context,f,user_data,help_text);
   newelem->f = f;
   newelem->user_data = user_data;
   newelem->context = context;
   newelem->keycode = keycode;
   llist_add_tail(&(TNG_MN(ptng)->element_header), newelem);
   return(OK);
}

errtype tng_menu_add_submenu(TNG *ptng, char *label, TNG *submenu)
{
   MenuElement *newelem;

   newelem = tng_menu_add_basic(ptng, label);
   newelem->submenu = submenu;
   llist_add_tail(&(TNG_MN(ptng)->element_header), newelem);
   return(OK);
}

MenuElement *tng_menu_add_basic(TNG *ptng, char *label)
{
   MenuElement *newelem;

   newelem = (MenuElement *)Malloc(sizeof(MenuElement));

   newelem->label = (char *)Malloc(sizeof(char) * (strlen(label) + 1));
   strcpy(newelem->label,label);

   newelem->submenu = NULL;
   newelem->f = NULL;
   newelem->user_data = NULL;
   newelem->keycode = 0;
   newelem->context = NULL;

   TNG_MN(ptng)->size.y += TNG_MN(ptng)->slot_height;
   TNG_MN(ptng)->num_lines++;
   if (TNG_MN(ptng)->current_selection == NULL)
      TNG_MN(ptng)->current_selection = newelem;
   return(newelem);      
}

errtype tng_menu_popup(TNG *ptng)
{
   if (!(TNG_MN(ptng)->popped_up))
      TNG_MN(ptng)->popup_func(ptng);
   return(OK);
}

errtype tng_menu_popup_at_mouse(TNG *ptng)
{
   Point mloc;
   TNG_GET_MOUSE(&(mloc.x), &(mloc.y));
   return(tng_menu_popup_loc(ptng, mloc));
}

errtype tng_menu_popup_loc(TNG *ptng, Point poploc)
{
   Point screen_size;

   screen_size.x = TNG_SCREEN_SIZE_X(ptng);
   screen_size.y = TNG_SCREEN_SIZE_Y(ptng);
   if (poploc.x + TNG_MN(ptng)->size.x > screen_size.x)
      poploc.x = screen_size.x - TNG_MN(ptng)->size.x;
   if (poploc.y + TNG_MN(ptng)->size.y > screen_size.y)
      poploc.y = screen_size.y - TNG_MN(ptng)->size.y;
   TNG_MN(ptng)->coord = poploc;
   if (!(TNG_MN(ptng)->popped_up))
      TNG_MN(ptng)->popup_func(ptng);
   return(OK);
}


