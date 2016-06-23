<?php

/**
 * @file
 * Drush example module.
 */

/**
 * Implements hook_drush_command().
 */
function queue_example_drush_command() {

  // Simplest implementation.
  $items['queue-1'] = array();

  return $items;
}

/**
 * Simplest implementation.
 */
function drush_queue_example_queue_1() {
  drush_print('Example 1');
}