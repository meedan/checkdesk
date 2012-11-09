
Summary
-------

Absolute Messages module displays system messages in colored
horizontal bars on top of the page, similar to Stack Overflow /
Stack Exchange network notifications.


Features
--------

- when messages are displayed content is pushed down respectively, so that
  nothing is covered and everything could be still interacted with,
- each message has its own "Dismiss" (close) icon,
- optional "Dismiss all" icon is displayed if total number of messages exceeds
  value defined in module settings,
- messages could be dismissed automatically after a specific time -
  configurable in module settings for each message type separately,
- provides option to display only first n lines of each message,
  with remaining part shown after clicking on the message,
- provides separate permissions to administer and to access Absolute messages,
- uses standard jQuery library without other modules or plugins dependencies,
- falls back to standard Drupal's way of displaying messages when JS
  is not available (or when user does not have access absolute messages
  permission granted),
- provides option to skip "has_js" cookie checking, which disables fallback
  to standard Drupal messages if no JS has been detected (for example
  in case of Pressflow 6, which dropped "has_js" cookie completely).


Hooks
-----

- hook_messages_alter($messages) - allows other modules to update messages
  before they are displayed,
- hook_message_types_alter($message_types) - allows other modules to add new
  messages types in addition to default ones used by Drupal (status, warning
  and error) - useful for setting message automatic dismiss time in module
  configuration.


Installation
------------

- download/checkout and enable the module,
- grant permissions to relevant roles to access and/or
  administer absolute messages.


Maintainer
----------

Maciej Zgadzaj
http://drupal.org/user/271491
http://zgadzaj.com/
