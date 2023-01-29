wget -O /tmp/cf_v1.0.0_linux_64.zip https://github.com/xalanq/cf-tool/releases/download/v1.0.0/cf_v1.0.0_linux_64.zip && \
    unzip /tmp/cf_v1.0.0_linux_64.zip -d /tmp && \
    sudo mv /tmp/cf_v1.0.0_linux_64/cf /usr/local/bin && \
    rm -rf /tmp/cf_v1.0.0_linux_64.zip /tmp/cf_v1.0.0_linux_64
