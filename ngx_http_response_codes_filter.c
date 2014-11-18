#include <ngx_config.h>
#include <ngx_core.h>
#include <ngx_http.h>


typedef struct {
    ngx_flag_t enable;
} ngx_http_response_codes_conf_t;


static ngx_int_t ngx_http_response_codes_filter_init (ngx_conf_t*);


static ngx_http_module_t  ngx_http_log_request_speed_filter_ctx = {
  NULL,                                     /* preconfiguration */
  ngx_http_response_codes_filter_init,      /* postconfiguration */
  ngx_http_response_codes_create_main_conf, /* create main configuration */
  ngx_http_response_codes_init_main_conf,   /* init main configuration */
  NULL,                                     /* create server configuration */
  NULL,                                     /* merge server configuration */
  NULL,                                     /* create location configuration */
  NULL                                      /* merge location configuration */
};


ngx_module_t ngx_http_response_codes_filter_module = {
  NGX_MODULE_V1,
  &ngx_http_response_codes_filter_module_ctx,        /* module context */
  ngx_http_response_codes_filter_module_commands,    /* module directives */
  NGX_HTTP_MODULE,                                   /* module type */
  NULL,                                              /* init master */
  NULL,                                              /* init module */
  NULL,                                              /* init process */
  NULL,                                              /* init thread */
  NULL,                                              /* exit thread */
  NULL,                                              /* exit process */
  NULL,                                              /* exit master */
  NGX_MODULE_V1_PADDING
};


static ngx_int_t
ngx_http_response_codes_filter_init(ngx_conf_t *cf)
{
    ngx_http_next_header_filter = ngx_http_top_header_filter;
    ngx_http_top_header_filter = ngx_http_response_codes_header_filter;

    return NGX_OK;
}
