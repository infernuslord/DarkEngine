extern "C" int kbd_modifier_state;

extern "C" int hack_for_kbd_state(void)
{
   return kbd_modifier_state;
}
