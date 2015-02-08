#include <pebble.h>

static Window *window;

static Layer *layer;
static InverterLayer *invertLayer;

static GBitmap *image0;
static GBitmap *image1;
static GBitmap *image2;
static GBitmap *image3;
static GBitmap *image4;
static GBitmap *image5;
static GBitmap *image6;
static GBitmap *image7;
static GBitmap *image8;
static GBitmap *image9;

static GBitmap *imageD0;
static GBitmap *imageD1;
static GBitmap *imageD2;
static GBitmap *imageD3;
static GBitmap *imageD4;
static GBitmap *imageD5;
static GBitmap *imageD6;
static GBitmap *imageD7;
static GBitmap *imageD8;
static GBitmap *imageD9;

static GBitmap *imageW;
static GBitmap *imageU;
static GBitmap *imageT;
static GBitmap *imageS;
static GBitmap *imageR;
static GBitmap *imageM;
static GBitmap *imageH;
static GBitmap *imageF;
static GBitmap *imageE;
static GBitmap *imageA;

static GBitmap *imageDot;
  

static char hour_buffer[3];
static char min_buffer[3];
static char day_buffer[3];
static char month_buffer[3];
static char day_name_buffer[4];
static void tick_handler(struct tm *tick_time, TimeUnits units_changed) {
  // Update things here
APP_LOG(APP_LOG_LEVEL_DEBUG, "We'reUpdatingTime");
if (clock_is_24h_style()) {
  strftime(hour_buffer, sizeof(hour_buffer), "%H", tick_time);
} else {
  strftime(hour_buffer, sizeof(hour_buffer), "%I", tick_time);
}
strftime(min_buffer, sizeof(min_buffer), "%M", tick_time);

strftime(day_buffer, sizeof(day_buffer), "%d", tick_time);

strftime(day_name_buffer, sizeof(day_name_buffer), "%a", tick_time);
strftime(month_buffer, sizeof(month_buffer), "%m", tick_time);

layer_mark_dirty(layer);

//text_layer_set_text(some_text_layer, s_time_buffer);s_tim
  
}
GBitmap* imageRefForLChar(char ch){
  if(ch=='W' || ch=='w'){
    return imageW;
  }else if(ch=='U'||ch=='u'){
    return imageU;
  }else if(ch=='T'||ch=='t'){
    return imageT;
  }else if(ch=='S'||ch=='s'){
    return imageS;
  }else if(ch=='R'||ch=='r'){
    return imageR;
  }else if(ch=='M'||ch=='m'){
    return imageM;
  }else if(ch=='H'||ch=='h'){
    return imageH;
  }else if(ch=='F'||ch=='f'){
    return imageF;
  }else if(ch=='E'||ch=='e'){
    return imageE;
  }else if(ch=='O'||ch=='o'){
    return imageD0;
  }else{
    return imageA;
  }
 
}
GBitmap* imageRefForChar(char ch){
  //return image0;
  if(ch=='0'){
    return image0;
  }else if(ch=='1'){
    return image1;
  }else if(ch=='2'){
    return image2;
  }else if(ch=='3'){
    return image3;
  }else if(ch=='4'){
    return image4;
  }else if(ch=='5'){
    return image5;
  }else if(ch=='6'){
    return image6;
  }else if(ch=='7'){
    return image7;
  }else if(ch=='8'){
    return image8;
  }else{
    return image9;
  }
}
GBitmap* imageDRefForChar(char ch){
  //return imageD0;
  if(ch=='0'){
    return imageD0;
  }else if(ch=='1'){
    return imageD1;
  }else if(ch=='2'){
    return imageD2;
  }else if(ch=='3'){
    return imageD3;
  }else if(ch=='4'){
    return imageD4;
  }else if(ch=='5'){
    return imageD5;
  }else if(ch=='6'){
    return imageD6;
  }else if(ch=='7'){
    return imageD7;
  }else if(ch=='8'){
    return imageD8;
  }else{
    return imageD9;
  }
}

static void layer_update_callback(Layer *me, GContext* ctx) {
  // We make sure the dimensions of the GRect to draw into
  // are equal to the size of the bitmap--otherwise the image
  // will automatically tile. Which might be what *you* want.
GBitmap* hour1=imageRefForChar(hour_buffer[0]);
GBitmap* hour2=imageRefForChar(hour_buffer[1]);
GBitmap* min1=imageRefForChar(min_buffer[0]);
GBitmap* min2=imageRefForChar(min_buffer[1]);
GBitmap* dayn1=imageRefForLChar(day_name_buffer[0]);
GBitmap* dayn2=imageRefForLChar(day_name_buffer[1]);

GBitmap* day1=imageDRefForChar(day_buffer[0]);
GBitmap* day2=imageDRefForChar(day_buffer[1]);
  
GBitmap* mon1=imageDRefForChar(month_buffer[0]);
GBitmap* mon2=imageDRefForChar(month_buffer[1]);

  graphics_draw_bitmap_in_rect(ctx, dayn1, (GRect) { .origin = { 0, 0 }, .size = { 20, 28 } });
  graphics_draw_bitmap_in_rect(ctx, dayn2, (GRect) { .origin = { 22, 0 }, .size = { 20, 28 } });
  
  graphics_draw_bitmap_in_rect(ctx, imageDot, (GRect) { .origin = { 44, 23 }, .size = { 5, 5 } });
  
  graphics_draw_bitmap_in_rect(ctx, day1, (GRect) { .origin = { 51, 0 }, .size = { 20, 28 } });
  graphics_draw_bitmap_in_rect(ctx, day2, (GRect) { .origin = { 73, 0 }, .size = { 20, 28 } });
  
  graphics_draw_bitmap_in_rect(ctx, imageDot, (GRect) { .origin = { 95, 23 }, .size = { 5, 5 } });
  
  graphics_draw_bitmap_in_rect(ctx, mon1, (GRect) { .origin = { 102, 0 }, .size = { 20, 28 } });
  graphics_draw_bitmap_in_rect(ctx, mon2, (GRect) { .origin = { 124, 0 }, .size = { 20, 28 } });
  
  graphics_draw_bitmap_in_rect(ctx, min1, (GRect) { .origin = { 0, 100 }, .size = { 71, 68 } });
  graphics_draw_bitmap_in_rect(ctx, min2, (GRect) { .origin = { 73, 100 }, .size = { 71, 68 } });
  graphics_draw_bitmap_in_rect(ctx, hour1, (GRect) { .origin = { 0, 30 }, .size = { 71, 68 } });
  graphics_draw_bitmap_in_rect(ctx, hour2, (GRect) { .origin = { 73, 30 }, .size = { 71, 68 } });
  
  
}

int main(void) {
  tick_timer_service_subscribe(MINUTE_UNIT, tick_handler);
  
  strcpy(hour_buffer,"10");
  strcpy(min_buffer,"01");
  //APP_LOG(APP_LOG_LEVEL_INFO, "TimeS: %s", hour_buffer);
  window = window_create();
  
  window_stack_push(window, true /* Animated */);
  
  // Init the layer for display the image
  Layer *window_layer = window_get_root_layer(window);
  
  GRect bounds = layer_get_frame(window_layer);
  invertLayer=inverter_layer_create(bounds);
  layer = layer_create(bounds);
  layer_set_update_proc(layer, layer_update_callback);
  layer_add_child(window_layer, inverter_layer_get_layer(invertLayer));
  layer_add_child(window_layer, layer);
  image0 = gbitmap_create_with_resource(RESOURCE_ID_TIME_NUMBER_0);
  image1 = gbitmap_create_with_resource(RESOURCE_ID_TIME_NUMBER_1);
  image2 = gbitmap_create_with_resource(RESOURCE_ID_TIME_NUMBER_2);
  image3 = gbitmap_create_with_resource(RESOURCE_ID_TIME_NUMBER_3);
  image4 = gbitmap_create_with_resource(RESOURCE_ID_TIME_NUMBER_4);
  image5 = gbitmap_create_with_resource(RESOURCE_ID_TIME_NUMBER_5);
  image6 = gbitmap_create_with_resource(RESOURCE_ID_TIME_NUMBER_6);
  image7 = gbitmap_create_with_resource(RESOURCE_ID_TIME_NUMBER_7);
  image8 = gbitmap_create_with_resource(RESOURCE_ID_TIME_NUMBER_8);
  image9 = gbitmap_create_with_resource(RESOURCE_ID_TIME_NUMBER_9);
  
  imageDot=gbitmap_create_with_resource(RESOURCE_ID_IMAGE_DATE_DOT);
  
  imageW=gbitmap_create_with_resource(RESOURCE_ID_IMAGE_DATE_W);
imageU=gbitmap_create_with_resource(RESOURCE_ID_IMAGE_DATE_U);
imageT=gbitmap_create_with_resource(RESOURCE_ID_IMAGE_DATE_T);
imageS=gbitmap_create_with_resource(RESOURCE_ID_IMAGE_DATE_S);
imageR=gbitmap_create_with_resource(RESOURCE_ID_IMAGE_DATE_R);
imageM=gbitmap_create_with_resource(RESOURCE_ID_IMAGE_DATE_M);
imageH=gbitmap_create_with_resource(RESOURCE_ID_IMAGE_DATE_H);
imageF=gbitmap_create_with_resource(RESOURCE_ID_IMAGE_DATE_F);
imageE=gbitmap_create_with_resource(RESOURCE_ID_IMAGE_DATE_E);
imageA=gbitmap_create_with_resource(RESOURCE_ID_IMAGE_DATE_A);

imageD0=gbitmap_create_with_resource(RESOURCE_ID_IMAGE_DATE_0);
imageD1=gbitmap_create_with_resource(RESOURCE_ID_IMAGE_DATE_1);
imageD2=gbitmap_create_with_resource(RESOURCE_ID_IMAGE_DATE_2);
imageD3=gbitmap_create_with_resource(RESOURCE_ID_IMAGE_DATE_3);
imageD4=gbitmap_create_with_resource(RESOURCE_ID_IMAGE_DATE_4);
imageD5=gbitmap_create_with_resource(RESOURCE_ID_IMAGE_DATE_5);
imageD6=gbitmap_create_with_resource(RESOURCE_ID_IMAGE_DATE_6);
imageD7=gbitmap_create_with_resource(RESOURCE_ID_IMAGE_DATE_7);
imageD8=gbitmap_create_with_resource(RESOURCE_ID_IMAGE_DATE_8);
imageD9=gbitmap_create_with_resource(RESOURCE_ID_IMAGE_DATE_9);
  
  app_event_loop();

  gbitmap_destroy(image0);
  gbitmap_destroy(image1);
  gbitmap_destroy(image2);
  gbitmap_destroy(image3);
  gbitmap_destroy(image4);
  gbitmap_destroy(image5);
  gbitmap_destroy(image6);
  gbitmap_destroy(image7);
  gbitmap_destroy(image8);
  gbitmap_destroy(image9);
  
    gbitmap_destroy(imageD0);
  gbitmap_destroy(imageD1);
  gbitmap_destroy(imageD2);
  gbitmap_destroy(imageD3);
  gbitmap_destroy(imageD4);
  gbitmap_destroy(imageD5);
  gbitmap_destroy(imageD6);
  gbitmap_destroy(imageD7);
  gbitmap_destroy(imageD8);
  gbitmap_destroy(imageD9);
  
    gbitmap_destroy(imageW);
  gbitmap_destroy(imageU);
  gbitmap_destroy(imageT);
  gbitmap_destroy(imageS);
  gbitmap_destroy(imageR);
  gbitmap_destroy(imageM);
  gbitmap_destroy(imageH);
  gbitmap_destroy(imageF);
  gbitmap_destroy(imageE);
  gbitmap_destroy(imageA);
  window_destroy(window);
  layer_destroy(layer);
}