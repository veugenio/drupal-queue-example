<?php

/**
 * Simplest queue implementation.
 */

/**
 * Menu callback.
 */
function queue_example_1() {
  $queue = DrupalQueue::get('queue_example_1');
  $queue->createQueue();
  $queue->createItem('Test');

  dpm($queue->claimItem());
  dpm($queue->numberOfItems());
}
