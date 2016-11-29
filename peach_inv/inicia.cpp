

/*

int inicializar(ALLEGRO_TIMER *timer,ALLEGRO_MONITOR_INFO info,ALLEGRO_DISPLAY *display){
    if(!al_init()){
        cerr<<"no se pudo inicializar allegro"<<endl;
        return -1;
    }


    al_init_font_addon();
    al_init_ttf_addon();
    al_install_keyboard();
    timer = al_create_timer(1.0 / FPS);
    if(!timer) {
      cerr<< "failed to create timer!\n"<<endl;
      return -1;
    }
    al_get_monitor_info(0,&info);
    display = al_create_display(info.x2, info.y2);

    if(!display){
        cerr<<"no se pudo configurar la pantalla"<<endl;
        return -1;
    }
    if(!al_init_image_addon()) {
      al_show_native_message_box(display, "Error", "Error", "no se pudo inicializar libreria",
                                 NULL, ALLEGRO_MESSAGEBOX_ERROR);
      return 0;
    }


  //  al_draw_bitmap(image,0,0,0);
   // al_draw_bitmap(p.get_image(), p.get_x(),p.get_y(),0);
    al_start_timer(timer);
    /*al_draw_text(font, color, info.x2/2,info.y2/2 -200,ALLEGRO_ALIGN_CENTRE, "Puntos: ");
    al_draw_text(font, color, (info.x2/2)+170,info.y2/2 -200,ALLEGRO_ALIGN_CENTRE, pchar);
    al_draw_text(font, color, info.x2/2,info.y2/2,ALLEGRO_ALIGN_CENTRE, cchar);
    al_draw_text(font, color, info.x2/2+100,info.y2/2,ALLEGRO_ALIGN_CENTRE, "$");*/
//}
