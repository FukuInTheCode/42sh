FROM ubuntu:latest
LABEL authors="antoiix"
WORKDIR /tester/
COPY . /tester/
RUN chmod 000 noaccess
RUN apt update && apt install -y tcsh
CMD ./tester.sh