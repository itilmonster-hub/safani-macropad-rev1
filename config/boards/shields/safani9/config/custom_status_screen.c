#include <zmk/display/status_screen.h>
#include <zmk/display/widgets/layer_status.h>
#include <zmk/display/widgets/battery_status.h>
#include <lvgl.h>

// ======================
// LOGO (Contoh Bitmap)
// ======================
static const uint8_t my_logo_map[] = {
    // Ukuran 128x32 bitmap data di sini
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
};

static lv_obj_t *logo_img;

// ======================
// INIT SCREEN (SINGLE OLED)
// ======================
lv_obj_t *zmk_display_status_screen(lv_obj_t *parent) {
    lv_obj_t *screen = lv_obj_create(parent, NULL);

    // 1. Status Layer Aktif (di pojok kiri atas)
    struct zmk_widget_layer_status *layer_widget = zmk_widget_layer_status_new(screen);
    lv_obj_align(layer_widget->obj, NULL, LV_ALIGN_TOP_LEFT, 0, 0);

    // 2. Status Baterai (di pojok kanan atas)
    struct zmk_widget_battery_status *battery_widget = zmk_widget_battery_status_new(screen);
    lv_obj_align(battery_widget->obj, NULL, LV_ALIGN_TOP_RIGHT, 0, 0);

    // 3. Tampilan Logo / Gambar (di tengah atau posisi lain)
    logo_img = lv_img_create(screen, NULL);
    // Jika menggunakan format LVGL image descriptor, pastikan sumber diatur dengan benar:
    // lv_img_set_src(logo_img, &my_logo_map); 
    lv_obj_align(logo_img, NULL, LV_ALIGN_CENTER, 0, 6);

    return screen;
}
