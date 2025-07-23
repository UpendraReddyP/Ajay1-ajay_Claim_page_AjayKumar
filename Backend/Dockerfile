# Use official Node.js base image
FROM node:18

# Set working directory
WORKDIR /app

# Copy and install dependencies
COPY package*.json ./
RUN npm install

# Copy app source
COPY . .

# Expose backend port
EXPOSE 3105

# Start the server directly (no wait script)
CMD ["node", "server.js"]

