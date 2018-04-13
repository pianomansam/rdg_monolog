<?php

/**
 * @file
 * Handler include for ErrorLogHandler.
 */

use Monolog\Handler\ErrorLogHandler;
use Monolog\Formatter\JsonFormatter;

/**
 * Monolog loader callback; Loads a ErrorLogHandler handler.
 *
 * @return HandlerInterface
 */
function monolog_rdg_error_log_json_handler_loader($options) {
  $handler = new ErrorLogHandler(ErrorLogHandler::OPERATING_SYSTEM, $options['level'], $options['bubble']);
    $formatter = new JsonFormatter();
  $handler->setFormatter($formatter);
  return $handler;
}
