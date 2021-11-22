#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "MQTTClient.h"
#include <wiringPiI2C.h>

#define ADDRESS "tcp://broker.hivemq.com:1883"
#define CLIENTID "BVMD-SENSOR"
#define TOPIC "BVMD-DATA"
#define QOS 0
#define TIMEOUT 10000L

#define DEVICE_ID 0x48
#define REG_TEMP 0x00

char buffer[50];

int main(int argc, char *argv[])
{
    // Setup I2C communication
    int fd = wiringPiI2CSetup(DEVICE_ID);
    if (fd == -1)
    {
        printf("Failed to init I2C communication.\n");
        return -1;
    }
    printf("I2C communication successfully setup.\n");

    int temperatuur = wiringPiI2CReadReg8(fd, REG_TEMP);

    printf("De temperatuur is %d\n", temperatuur);
    sprintf(buffer, "%d", temperatuur);

    MQTTClient client;
    MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
    MQTTClient_message pubmsg = MQTTClient_message_initializer;
    MQTTClient_deliveryToken token;
    int rc;

    MQTTClient_create(&client, ADDRESS, CLIENTID,
                      MQTTCLIENT_PERSISTENCE_NONE, NULL);
    conn_opts.keepAliveInterval = 20;
    conn_opts.cleansession = 1;

    if ((rc = MQTTClient_connect(client, &conn_opts)) != MQTTCLIENT_SUCCESS)
    {
        printf("Failed to connect, return code %d\n", rc);
        exit(-1);
    }
    pubmsg.payload = buffer;
    pubmsg.payloadlen = strlen(buffer);
    pubmsg.qos = QOS;
    pubmsg.retained = 0;
    MQTTClient_publishMessage(client, TOPIC, &pubmsg, &token);
    printf("Waiting for up to %d seconds for publication of %s\n"
           "on topic %s for client with ClientID: %s\n",
           (int)(TIMEOUT / 1000), buffer, TOPIC, CLIENTID);
    rc = MQTTClient_waitForCompletion(client, token, TIMEOUT);
    printf("Message with delivery token %d delivered\n", token);
    MQTTClient_disconnect(client, 10000);
    MQTTClient_destroy(&client);
    return rc;
}