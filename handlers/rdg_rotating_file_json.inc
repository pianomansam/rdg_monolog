<?php

/**
 * @file
 * Handler include for StreamHandler.
 */

use Monolog\Handler\RotatingFileHandler;
use Monolog\Formatter\JsonFormatter;

/**
 * Monolog loader callback; Loads a RotatingFileHandler handler.
 *
 * @return HandlerInterface
 */
function monolog_rdg_rotating_file_json_handler_loader($options) {
  $directory = dirname($options['filepath']);
  monolog_prepare_log_dir($directory);
  $handler = new RotatingFileHandler($options['filepath'], $options['max_files'], $options['level'], $options['bubble']);
  $formatter = new JsonFormatter();
  $handler->setFormatter($formatter);
  return $handler;
}

/**
 * Monolog settings form; Settings for the RotatingFileHandler handler.
 */
function monolog_rdg_rotating_file_json_handler_settings(&$form, &$form_state, $profile, array $handler) {

  $form['filepath'] = array(
    '#title' => t('Log file path'),
    '#type' => 'textfield',
    '#default_value' => $handler['filepath'],
    '#description' => t('The path or URI that the log file will be written to.'),
  );

  $form['max_files'] = array(
    '#title' => t('Maximum number of files'),
    '#type' => 'textfield',
    '#default_value' => $handler['max_files'],
    '#description' => t('The maximal amount of files to keep (0 means unlimited).'),
    '#size' => 4,
  );
}
