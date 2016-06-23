<?php

/**
 * Simplest queue implementation.
 */

/**
 * Menu callback.
 */
function queue_example_1($form, &$form_state) {
  
  $form['create_queue'] = array(
    '#type' => 'button',
    '#value' => t('Create queue'),
    '#ajax' => array(
      'callback' => 'queue_example_create_simple_queue',
      'wrapper' => 'result',
     ),
  );

  $form['create_item'] = array(
    '#type' => 'button',
    '#value' => t('Create item'),
    '#ajax' => array(
      'callback' => 'queue_example_create_item',
      'wrapper' => 'result',
     ),
  );
  
  $form['count_items'] = array(
    '#type' => 'button',
    '#value' => t('Count items'),
    '#ajax' => array(
      'callback' => 'queue_example_count_items',
      'wrapper' => 'result',
     ),
  );

  $form['claim_item'] = array(
    '#type' => 'button',
    '#value' => t('Claim item'),
    '#ajax' => array(
      'callback' => 'queue_example_claim_item',
      'wrapper' => 'result',
     ),
  );

  $form['result'] = array(
    '#markup' => '<div id="result"></div>'
  );

  return $form;
}

/**
 * Creating a simple DrupalQueue.
 */
function queue_example_create_simple_queue() {
  $queue = DrupalQueue::get('simple');
  $queue->createQueue();
  return queue_example_result_wrapper($queue);
}

/**
 * Create an item.
 */
function queue_example_create_item() {
  $item = 'coisa ' . rand(1, 100);

  $queue = DrupalQueue::get('simple');
  $queue->createItem($item);
  return queue_example_result_wrapper($item);
}

/**
 * Number total of items.
 */
function queue_example_count_items() {
  $queue = DrupalQueue::get('simple');
  $total = $queue->numberOfItems();
  return queue_example_result_wrapper($total);
}

/**
 * Claim item.
 */
function queue_example_claim_item() {
  $queue = DrupalQueue::get('simple');
  $item = $queue->claimItem(1);
  return queue_example_result_wrapper($item);
}

/**
 * Ajax result wrapper.
 */
function queue_example_result_wrapper($result) {
  return '<div id="result">' . print_r($result, TRUE) . '</div>';
}

class MyQueue extends SystemQueue implements DrupalQueueInterface {
  
}