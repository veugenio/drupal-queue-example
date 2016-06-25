<?php

/**
 * Queue with another class.
 */

/**
 * Menu callback.
 */
function queue_example_1_1() {
  variable_set('queue_class_queue_example_1_1', 'MemoryQueue');

  $queue = DrupalQueue::get('queue_example_1_1');
  $queue->createQueue();
  $queue->createItem('Test');

  dpm($queue->claimItem());
  dpm($queue->numberOfItems());
}
