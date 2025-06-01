import axios from 'axios';

const apiClient = axios.create({
  baseURL: 'http://localhost:8080/api/messages'
});

export const getMessages = async (currentUser: string, withUser: string) => {
  const response = await apiClient.get('', {
    params: { withUser },
    headers: { 'X-User-Id': currentUser }
  });
  return response.data;
};

export const sendMessage = async (currentUser: string, recipient: string, content: string) => {
  const response = await apiClient.post('', 
    { content, recipient },
    { headers: { 'X-User-Id': currentUser } }
  );
  return response.data;
};