FROM ubuntu:20.04
MAINTAINER Jack-R-lantern

RUN apt update && apt install -y gcc man-db
RUN apt install -y libcap-dev && apt install -y psmisc
RUN apt install -y libseccomp-dev
RUN yes | unminimize

CMD ["bash"]