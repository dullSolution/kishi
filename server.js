// server.js
const express = require('express');
const axios = require('axios');
const app = express();
const PORT = 3000;

// 托管静态文件
app.use(express.static('public'));

// 解析JSON请求体
app.use(express.json());

// 代理API请求（解决CORS问题）
app.post('/api/generate', async (req, res) => {
  try {
    const { prompt, model = 'flux', width = 512, height = 512, seed } = req.body;

    // 构建API URL
    const baseUrl = 'https://image.pollinations.ai/prompt';
    const encodedPrompt = encodeURIComponent(prompt);
    let apiUrl = `${baseUrl}/${encodedPrompt}?model=${model}&width=${width}&height=${height}`;
    if (seed) apiUrl += `&seed=${seed}`;

    // 获取图像数据
    const response = await axios.get(apiUrl, {
      responseType: 'stream'
    });

    // 返回图像流
    res.set('Content-Type', 'image/png');
    response.data.pipe(res);
  } catch (error) {
    console.error('生成错误:', error);
    res.status(500).json({ error: error.message });
  }
});

app.listen(PORT, () => {
  console.log(`Server running at http://localhost:${PORT}`);
});