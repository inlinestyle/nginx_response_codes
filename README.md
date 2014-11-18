nginx_response_codes
====================

#IN DEVELOPMENT; DO NOT USE!


Metrics on the response codes from your nginx server!


####Build (may need root access YMMV):
```bash
./configure --add-module=path/to/repo/nginx_response_codes
make
make install
```

####Basic usage (in an nginx config file):
```nginx
events {
    worker_connections 1024;
}

http {
    response_codes on;
    server {
        root /www/data;
        location / {
        }
    }
}
```
