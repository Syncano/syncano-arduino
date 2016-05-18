# Arduino Library for Syncano

Arduino library for Syncano provides support for Arduino Yún.

This library let you use Syncano as Cloud for your connected devices.

In case of any questions or feedback, please do not hesitate to contact us on: `#iot` channel at [Syncano-community Slack](https://syncano-community.slack.com/messages/iot/)

## Getting started

This library is inteded to be used with a [Syncano](https://www.syncano.io/) account. If you don't already have one - you can sign up [here](https://dashboard.syncano.io/?utm_source=github&amp;utm_medium=readme&amp;utm_campaign=syncano-js).

### Channels

In order to use Syncano channels, you have to create the template in Syncano. Templates can be found in `<> Snippets` section in your dashboard. 
Name your new template `arduino` and set it content type to `application/json`. Then just copy the code below into it and save.
~~~~
{%- set fields_to_skip = [
        "group",
        "group_permissions",
        "owner_permissions",
        "other_permissions",
        "owner",
        "revision",
        "updated_at",
        "created_at"
    ]
-%}
{%- if action == 'create' or action =='partial_update' -%}
    {%- if 'id' in response -%}
        {{response.id|int()}}
    {%- elif 'status' or 'type' in response -%}
        {{'1'|int()}}
    {%- else -%}
        {{'0'|int()}}
    {%- endif -%}
{%- elif payload -%}
{
    {%- for key, value in payload.iteritems() if key not in fields_to_skip -%}
        "{{key}}":
        {%- if value is number -%}
            {{value}}
        {%- else -%}
            "{{value}}"
        {%- endif -%}
        {%- if not loop.last -%}
            ,
        {%- endif -%}
    {%- endfor -%}
}  
{%- endif -%}
~~~~

### Installation

To use this library copy folder SyncanoArduinoLibrary from [GitHub](https://github.com/Syncano/syncano-arduino/archive/master.zip) to your Custom Arduino Library Folder.

### Include library

In your sketch you have to include library.
~~~~ c++
#include <Syncano.h>
~~~~

### Define consts
Next you have to define your Syncano Api Key
~~~~ c++
#define ACCOUNT_KEY "API_KEY"
~~~~
Optionally you can define other const like Syncano Instance Name, Object Id or Webhook Name.
### Setup your sketch
Before setup function you have to define pointer to Syncano object:
~~~~ c++
SyncanoClient* syncano;
~~~~

In setup function you can prepare syncano object to connect to Syncano.io
~~~~ c++
initSyncanoClient(ACCOUNT_KEY);
syncano = getSyncanoClient();
syncano->setInstanceName("INSTANCE_NAME");
~~~~

### Main loop

For example, you can use library to parse Syncano classes.
First you have to create Class in Syncano ( or use existing ), then you can use details() method to fetch Class schema to local object.
After this step you can create object based on this class or simply write class fields to Serial output by using printDetails() method.

~~~~ c++
SyncanoClass* classHolder = new SyncanoClass(CLASS_NAME);

Serial.println("Class details example:");
classHolder->details();
classHolder->printDetails();
~~~~

## Documentation

If you want to generate local version of documentation, simply use [doxygen](http://www.stack.nl/~dimitri/doxygen/index.html) with additional [graphviz](http://www.graphviz.org/) tool installed. 

[Doxygen installation instruction](http://www.stack.nl/~dimitri/doxygen/download.html)

Generating documentation on Ubuntu:
~~~~ bash
sudo apt-get install doxygen graphviz
cd [PATH_TO_LIBRARY_DIR]
doxygen ./Doxyfile
~~~~
Documentation can be found in new directory called *auto_docs*

You can also visit our  [documentation website](http://docs.eyedea.ninja/) for actual documentation version.

## Examples
We have prepared set of examples ready to use with Syncano. You can find them on our [GitHub site](https://github.com/Syncano/syncano-arduino/tree/master/examples), [Playground](http://eyedea.ninja/) or directly in your Adruino IDE in examples section.
