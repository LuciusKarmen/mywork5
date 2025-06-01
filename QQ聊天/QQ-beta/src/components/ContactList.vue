<template>
  <div class="contact-list">
    <h3>联系人</h3>
    <ul>
      <li 
        v-for="contact in contacts" 
        :key="contact"
        @click="$emit('select-contact', contact)"
        :class="{ active: contact === selectedContact }"
      >
        {{ contact }}
      </li>
    </ul>
  </div>
</template>

<script setup lang="ts">
defineProps<{
  contacts: string[];
  selectedContact: string | null;
}>();

defineEmits<{
  (e: 'select-contact', contact: string): void;
}>();
</script>