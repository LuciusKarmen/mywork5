<script setup lang="ts" name="ContactList">
defineProps<{
  contacts: string[]
}>()

const emit = defineEmits<{
  (e: 'select-contact', contact: string): void
}>()
</script>

<template>
  <div class="contact-list">
    <h3>联系人</h3>
    <ul>
      <li v-for="contact in contacts" :key="contact" @click="$emit('select-contact', contact)">
        {{ contact }}
      </li>
    </ul>
  </div>
</template>

<style scoped>
.contact-list ul {
  list-style: none;
  padding: 0;
}

.contact-list li {
  padding: 10px;
  cursor: pointer;
}

.contact-list li:hover {
  background-color: #f0f0f0;
}
</style>
