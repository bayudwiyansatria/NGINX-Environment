# Proxy settings
proxy_redirect      off;
proxy_set_header    Host                $host;

#proxy_set_header Host $upstream_addr;
proxy_set_header    X-Real-IP           $remote_addr;
proxy_set_header    X-Forwarded-For     $proxy_add_x_forwarded_for;
proxy_set_header    X-Forwarded-Proto   $scheme;

proxy_pass_header   Set-Cookie;

proxy_connect_timeout   90;
proxy_send_timeout      90;
proxy_read_timeout      90;
proxy_buffers           32 4k;

#proxy_cache_path /var/cache/nginx levels=2 keys_zone=cache:10m inactive=60m max_size=512m;
proxy_cache_key "$host$request_uri $cookie_user";
proxy_temp_path  /var/cache/nginx/temp;

proxy_ignore_headers Expires Cache-Control;
proxy_cache_use_stale error timeout invalid_header http_502;
proxy_cache_valid any 1d;
