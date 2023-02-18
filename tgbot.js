const mavka = getMavka();
const context = getContext();

const mapTelegramChat = (chat) => chat && ({});
const mapTelegramUser = (chat) => chat && ({});
const mapTelegramAnimation = (chat) => chat && ({});
const mapTelegramAudio = (chat) => chat && ({});
const mapTelegramVideo = (chat) => chat && ({});
const mapTelegramDocument = (chat) => chat && ({});
const mapTelegramPhotoSize = (chat) => chat && ({});
const mapTelegramSticker = (chat) => chat && ({});
const mapTelegramVideoNote = (chat) => chat && ({});
const mapTelegramVoice = (chat) => chat && ({});
const mapTelegramPoll = (chat) => chat && ({});
const mapTelegramVenue = (chat) => chat && ({});
const mapTelegramContact = (chat) => chat && ({});
const mapTelegramLocation = (chat) => chat && ({});

const mapTelegramMessage = (message) => message && ({
  "айді_повідомлення": message.message_id,
  "від": message.from,
  "чат_відправника": message.sender_chat,
  "дата": message.date,
  "чат": message.chat,
  "переслано_від": message.forward_from,
  "переслано_від_чату": message.forward_from_chat,
  "переслано_від_айді_повідомлення": message.forward_from_message_id,
  "переслано_підпис": message.forward_signature,
  "переслано_ім'я_відправника": message.forward_sender_name,
  "переслано_дата": message.forward_date,
  "переслано_автоматично": message.is_automatic_forward,
  "переслано_на_повідомлення": mapTelegramMessage(message.reply_to_message),
  "через_бота": message.via_bot,
  "дата_редагування": message.edit_date,
  "має_захищений_контент": message.has_protected_content,
  "айді_медіа_групи": message.media_group_id,
  "підпис_автора": message.author_signature,
  "текст": message.text,
  "сутності": message.entities,
  "анімація": message.animation,
  "аудіо": message.audio,
  "документ": message.document,
  "фото": message.photo,
  "стікер": message.sticker,
  "відео": message.video,
  "відео_нотатка": message.video_note,
  "голосове": message.voice,
  "підпис": message.caption,
  "сутності_підпису": message.caption_entities,
  "контакт": message.contact,
  "кубик": message.dice,
  "гра": message.game,
  "опитування": message.poll,
  "місце": message.venue,
  "локація": message.location,
  "нові_учасники_чату": message.new_chat_members,
  "покинувші_учасники_чату": message.left_chat_member,
  "новий_заголовок_чату": message.new_chat_title,
  "нове_фото_чату": message.new_chat_photo,
  "видалити_фото_чату": message.delete_chat_photo,
  "груповий_чат_створено": message.group_chat_created,
  "супергруповий_чат_створено": message.supergroup_chat_created,
  "канал_створено": message.channel_chat_created
  // "message_auto_delete_timer_changed": message.message_auto_delete_timer_changed,
  // "migrate_to_chat_id": message.migrate_to_chat_id,
  // "migrate_from_chat_id": message.migrate_from_chat_id,
  // "pinned_message": message.pinned_message,
  // "invoice": message.invoice,
  // "successful_payment": message.successful_payment,
  // "connected_website": message.connected_website,
  // "passport_data": message.passport_data,
  // "proximity_alert_triggered": message.proximity_alert_triggered,
  // "video_chat_scheduled": message.video_chat_scheduled,
  // "video_chat_started": message.video_chat_started,
  // "video_chat_ended": message.video_chat_ended,
  // "video_chat_participants_invited": message.video_chat_participants_invited,
  // "web_app_data": message.web_app_data,
  // "reply_markup": message.reply_markup
});

const mapTelegramUpdate = (update) => update && ({
  "айді_оновлення": update.update_id,
  "повідомлення": mapTelegramMessage(update.message),
  "відредаговане_повідомлення": mapTelegramMessage(update.edited_message),
  "публікація_каналу": mapTelegramMessage(update.channel_post),
  "відредагована_публікація_каналу": mapTelegramMessage(update.edited_channel_post),
  "відповідь_на_запит": update.callback_query,
  "опитування": update.poll,
  "відповідь_на_опитування": update.poll_answer,
  "запит_на_приєднання_до_чату": update.chat_join_request
});

context.set("бот_апі_отримати_список_оновлень", mavka.tools.asyncFn(context, async ([token, lastUpdateId]) => {
  const response = await fetch(`https://api.telegram.org/bot${token}/getUpdates`, {
    method: "post",
    body: JSON.stringify({
      offset: lastUpdateId ? lastUpdateId + 1 : null
    }),
    headers: {
      "Accept": "application/json",
      "Content-Type": "application/json"
    }
  });
  const { result } = await response.json();

  return result.map(mapTelegramUpdate);
}));

context.set("надіслати_повідомлення", mavka.tools.asyncFn(context, async ([token, message]) => {
  const response = await fetch(`https://api.telegram.org/bot${token}/sendMessage`, {
    method: "post",
    body: JSON.stringify({
      chat_id: message["айді_чату"],
      text: message["текст"]
    }),
    headers: {
      "Accept": "application/json",
      "Content-Type": "application/json"
    }
  });
  const { result } = await response.json();

  return mapTelegramMessage(result);
}));

await mavka.eval(`
модуль ТелеграмБот
  структура Бот
    токен текст
    останнє_оновлення Об'єкт
  кінець
  
  тривала дія Бот.слухати(слухач Дія)
    поки так
      якщо я.останнє_оновлення
        чекати список_оновлень = бот_апі_отримати_список_оновлень(я.токен, я.останнє_оновлення.айді_оновлення)
      інакше
        чекати список_оновлень = бот_апі_отримати_список_оновлень(я.токен, 0)
      кінець
  
      перебрати список_оновлень як оновлення
        слухач(оновлення)
        я.останнє_оновлення = оновлення
      кінець
    кінець 
  кінець
    
  структура Повідомлення
    айді_чату число
    текст текст
  кінець
  
  дати Бот
  дати Повідомлення
кінець
`, context);
